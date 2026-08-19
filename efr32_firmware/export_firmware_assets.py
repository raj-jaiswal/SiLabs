#!/usr/bin/env python3
"""
Silicon Labs EFR32 Firmware Asset Generator
Re-generates C header files (Decision Trees, Scalers, TFLite models)
from trained Python models for direct use in Gecko SDK / Simplicity Studio.
"""

import os
import json
import joblib

BASE_DIR = os.path.dirname(os.path.abspath(__file__))
PARENT_DIR = os.path.abspath(os.path.join(BASE_DIR, ".."))
INC_DIR = os.path.join(BASE_DIR, "inc")

os.makedirs(INC_DIR, exist_ok=True)

def find_file(filename, subdirs=None):
    candidates = [
        os.path.join(PARENT_DIR, filename),
    ]
    if subdirs:
        for sd in subdirs:
            candidates.append(os.path.join(PARENT_DIR, "models", sd, filename))
            candidates.append(os.path.join(PARENT_DIR, sd, filename))
    for c in candidates:
        if os.path.exists(c):
            return c
    return candidates[0]

def export_scaler_params():
    print("[1/3] Exporting StandardScaler parameters to scaler_params.h...")
    
    sc_hypo_file = find_file("scaler_Future_Hypotension.json", ["scalers"])
    sc_hypox_file = find_file("scaler_Future_Hypoxia.json", ["scalers"])
    sc_tachy_file = find_file("scaler_Future_Tachycardia.json", ["scalers"])

    with open(sc_hypo_file) as f:
        sc_hypo = json.load(f)
    with open(sc_hypox_file) as f:
        sc_hypox = json.load(f)
    with open(sc_tachy_file) as f:
        sc_tachy = json.load(f)

    feature_names = list(sc_hypo["mean"].keys())

    content = """#ifndef SCALER_PARAMS_H
#define SCALER_PARAMS_H

// Auto-generated StandardScaler parameters for Silicon Labs EFR32
// Features count: 95 (19 channels x 5 window statistics)

#define EFR32_NUM_FEATURES 95

// Feature names in exact sequential CSV column order
"""
    content += "static const char* const EFR32_FEATURE_NAMES[EFR32_NUM_FEATURES] = {\n"
    for f in feature_names:
        content += f'    "{f}",\n'
    content += "};\n\n"

    def fmt_arr(name, values):
        res = f"static const float {name}[EFR32_NUM_FEATURES] = {{\n    "
        res += ", ".join(f"{v:.6f}f" for v in values)
        res += "\n};\n\n"
        return res

    content += "// 1. Future_Hypotension Scaler\n"
    content += fmt_arr("SCALER_HYPOTENSION_MEAN", list(sc_hypo["mean"].values()))
    content += fmt_arr("SCALER_HYPOTENSION_SCALE", list(sc_hypo["std"].values()))

    content += "// 2. Future_Hypoxia Scaler\n"
    content += fmt_arr("SCALER_HYPOXIA_MEAN", list(sc_hypox["mean"].values()))
    content += fmt_arr("SCALER_HYPOXIA_SCALE", list(sc_hypox["std"].values()))

    content += "// 3. Future_Tachycardia Scaler\n"
    content += fmt_arr("SCALER_TACHYCARDIA_MEAN", list(sc_tachy["mean"].values()))
    content += fmt_arr("SCALER_TACHYCARDIA_SCALE", list(sc_tachy["std"].values()))

    content += "#endif // SCALER_PARAMS_H\n"

    out_file = os.path.join(INC_DIR, "scaler_params.h")
    with open(out_file, "w") as f:
        f.write(content)
    print(f"      Saved: {out_file}")

def export_decision_trees():
    print("[2/3] Exporting Decision Tree logic to efr32_decision_tree.h...")
    
    sc_hypo_file = find_file("scaler_Future_Hypotension.json", ["scalers"])
    with open(sc_hypo_file) as f:
        sc = json.load(f)
    feat_names = [f.replace("/", "_") for f in sc["mean"].keys()]

    def tree_to_c_func(tree_model, func_name, target_desc):
        tree_ = tree_model.tree_
        c_out = f"// {target_desc}\n"
        c_out += f"// Flash footprint: ~{tree_.node_count * 16 / 1024:.2f} KB | Dynamic RAM: 0 KB\n"
        c_out += f"static inline bool {func_name}(const float* features) {{\n"

        def recurse(node, depth):
            indent = "    " * depth
            if tree_.feature[node] != -2:
                feat_idx = tree_.feature[node]
                name = f"features[{feat_idx}] /* {feat_names[feat_idx]} */"
                threshold = tree_.threshold[node]
                s = f"{indent}if ({name} <= {threshold:.5f}f) {{\n"
                s += recurse(tree_.children_left[node], depth + 1)
                s += f"{indent}}} else {{\n"
                s += recurse(tree_.children_right[node], depth + 1)
                s += f"{indent}}}\n"
                return s
            else:
                val = tree_.value[node][0]
                prediction = "true" if val[1] > val[0] else "false"
                return f"{indent}return {prediction};\n"

        c_out += recurse(0, 1)
        c_out += "}\n\n"
        return c_out

    dt_hypo_path = find_file("efr32_dt_Future_Hypotension.joblib", ["decision_tree"])
    dt_hypox_path = find_file("efr32_dt_Future_Hypoxia.joblib", ["decision_tree"])
    dt_tachy_path = find_file("efr32_dt_Future_Tachycardia.joblib", ["decision_tree"])

    dt_hypo = joblib.load(dt_hypo_path)
    dt_hypox = joblib.load(dt_hypox_path)
    dt_tachy = joblib.load(dt_tachy_path)

    header = """#ifndef EFR32_DECISION_TREE_H
#define EFR32_DECISION_TREE_H

// Silicon Labs EFR32 Fast Direct C Decision Tree Classifiers
// Target Platforms: EFR32xG24, EFR32BG22, EFR32MG21, Cortex-M33/M4

#include <stdbool.h>

"""
    header += tree_to_c_func(dt_hypo, "predict_hypotension_efr32", "1. Future_Hypotension Classifier (MAP < 65 mmHg)")
    header += tree_to_c_func(dt_hypox, "predict_hypoxia_efr32", "2. Future_Hypoxia Classifier (SpO2 < 90%)")
    header += tree_to_c_func(dt_tachy, "predict_tachycardia_efr32", "3. Future_Tachycardia Classifier (HR > 100 bpm)")
    header += "#endif // EFR32_DECISION_TREE_H\n"

    out_file = os.path.join(INC_DIR, "efr32_decision_tree.h")
    with open(out_file, "w") as f:
        f.write(header)
    print(f"      Saved: {out_file}")

def export_tflite_header():
    print("[3/3] Exporting TFLite array to efr32_model_tflite.h...")
    tflite_src = find_file("efr32_model_tflite.h", ["tflite"])
    tflite_dst = os.path.join(INC_DIR, "efr32_model_tflite.h")
    if os.path.exists(tflite_src):
        with open(tflite_src, "r") as f_in, open(tflite_dst, "w") as f_out:
            f_out.write(f_in.read())
        print(f"      Saved: {tflite_dst}")

if __name__ == "__main__":
    export_scaler_params()
    export_decision_trees()
    export_tflite_header()
    print("\nAll EFR32 firmware assets exported successfully!")
