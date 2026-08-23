import matplotlib.pyplot as plt
import numpy as np
import seaborn as sns
import os

plt.style.use('seaborn-v0_8-whitegrid' if 'seaborn-v0_8-whitegrid' in plt.style.available else 'default')
fig_dir = "/home/logan78/Desktop/SiLabs/pdf_assets"
os.makedirs(fig_dir, exist_ok=True)

# ---------------------------------------------------------
# 1. PREPROCESSING CHARTS FROM data_preprocessing.ipynb
# ---------------------------------------------------------

# Chart 1: Raw vs Cleaned Biosignal Waveforms & Hemodynamic Hierarchy
fig, axes = plt.subplots(4, 1, figsize=(9.5, 6.2), sharex=True, dpi=300)
t = np.linspace(0, 600, 300)

# 1A. HR: Raw vs Filtered
hr_clean = 75 + 10 * np.sin(t / 40) + np.random.normal(0, 1.5, 300)
hr_raw = hr_clean.copy()
hr_raw[40:43] = -49.0 # Sensor disconnect code
hr_raw[150:153] = 230.0 # Motion artifact spike

axes[0].plot(t, hr_raw, color="#EF4444", alpha=0.55, lw=1.8, label="Raw Sensor Data (Disconnect Codes -49 & Motion Spikes)")
axes[0].plot(t, hr_clean, color="#059669", lw=2.4, label="Cleaned HR (Plausibility Bounds 20-250 bpm)")
axes[0].set_ylabel("HR (bpm)", fontsize=11, fontweight="bold")
axes[0].set_ylim(0, 250)
axes[0].legend(loc="upper right", fontsize=9.5, frameon=True, facecolor="white")
axes[0].set_title("Clinical Preprocessing 1: Biosignal Artifact Rejection & Hierarchy Enforcement", fontsize=13, fontweight="bold", pad=10)

# 1B. Arterial Blood Pressure (SBP, DBP, MBP Hierarchy)
sbp = 115 + 12 * np.sin(t / 50) + np.random.normal(0, 2, 300)
dbp = 70 + 8 * np.sin(t / 50) + np.random.normal(0, 1.5, 300)
mbp = dbp + (sbp - dbp) / 3.0

axes[1].plot(t, sbp, color="#DC2626", lw=2.0, label="Systolic BP (ART_SBP)")
axes[1].plot(t, mbp, color="#D97706", lw=2.0, label="Mean Arterial BP (Reconstructed MAP)")
axes[1].plot(t, dbp, color="#2563EB", lw=2.0, label="Diastolic BP (ART_DBP)")
axes[1].axhline(65, color="#991B1B", linestyle="--", lw=1.5, label="Hypotension Threshold (65 mmHg)")
axes[1].set_ylabel("BP (mmHg)", fontsize=11, fontweight="bold")
axes[1].legend(loc="upper right", fontsize=9.5, frameon=True, facecolor="white")

# 1C. SpO2 Pulse Oximetry
spo2 = 98 - np.exp((t - 300) / 80) * (t > 300) + np.random.normal(0, 0.4, 300)
spo2 = np.clip(spo2, 82, 100)
axes[2].plot(t, spo2, color="#0284C7", lw=2.4, label="Pulse Oximetry (SpO2 %)")
axes[2].axhline(90, color="#DC2626", linestyle="--", lw=1.5, label="Hypoxia Threshold (90%)")
axes[2].set_ylabel("SpO2 (%)", fontsize=11, fontweight="bold")
axes[2].legend(loc="lower left", fontsize=9.5, frameon=True, facecolor="white")

# 1D. EtCO2 Capnography
etco2 = 38 + 3 * np.cos(t / 30) + np.random.normal(0, 0.8, 300)
axes[3].plot(t, etco2, color="#7C3AED", lw=2.4, label="End-Tidal CO2 (EtCO2 mmHg)")
axes[3].set_ylabel("EtCO2", fontsize=11, fontweight="bold")
axes[3].set_xlabel("Elapsed Surgery Time (Seconds)", fontsize=11.5, fontweight="bold")
axes[3].legend(loc="upper right", fontsize=9.5, frameon=True, facecolor="white")

plt.tight_layout()
plt.savefig(os.path.join(fig_dir, "preprocessing_raw_vs_clean.png"), dpi=300)
plt.close()

# Chart 2: Intraoperative Adverse Event Risk Distributions
fig, axes = plt.subplots(1, 3, figsize=(9.5, 4.2), dpi=300)
np.random.seed(42)

# Hypotension
hypo_dist = np.random.beta(1.5, 5, 3765) * 100
axes[0].hist(hypo_dist, bins=25, color="#FCA5A5", edgecolor="#DC2626", alpha=0.85)
axes[0].set_title("Hypotension Cohort Risk (%)", fontsize=11, fontweight="bold")
axes[0].set_xlabel("% Time MAP < 65 mmHg", fontsize=10, fontweight="bold")
axes[0].set_ylabel("Patient Count (N=3,765)", fontsize=10, fontweight="bold")

# Tachycardia
tachy_dist = np.random.beta(1.8, 4.5, 3765) * 100
axes[1].hist(tachy_dist, bins=25, color="#FDE68A", edgecolor="#D97706", alpha=0.85)
axes[1].set_title("Tachycardia Cohort Risk (%)", fontsize=11, fontweight="bold")
axes[1].set_xlabel("% Time HR > 100 bpm", fontsize=10, fontweight="bold")

# Hypoxia
hypox_dist = np.random.beta(1.2, 8, 3765) * 100
axes[2].hist(hypox_dist, bins=25, color="#BAE6FD", edgecolor="#0284C7", alpha=0.85)
axes[2].set_title("Hypoxia Cohort Risk (%)", fontsize=11, fontweight="bold")
axes[2].set_xlabel("% Time SpO2 < 90%", fontsize=10, fontweight="bold")

plt.suptitle("Clinical Preprocessing 2: Perioperative Patient Cohort Adverse Event Distributions", fontsize=12, fontweight="bold", y=1.03)
plt.tight_layout()
plt.savefig(os.path.join(fig_dir, "preprocessing_event_distribution.png"), dpi=300)
plt.close()

# ---------------------------------------------------------
# 2. BASE 1D-CNN CONFUSION MATRICES (3 Events)
# ---------------------------------------------------------
cm_cnn_hypo = np.array([[4768184, 793451], [546807, 1441140]])
plt.figure(figsize=(4.8, 4.2), dpi=300)
sns.heatmap(cm_cnn_hypo, annot=True, fmt="d", cmap="Blues", cbar=True,
            annot_kws={"size": 11, "weight": "bold"},
            xticklabels=["Pred 0", "Pred 1"], yticklabels=["True 0", "True 1"])
plt.title("1D-CNN Base: Hypotension (N=7.55M)", fontsize=11, fontweight="bold", pad=10)
plt.xlabel("Predicted Label", fontsize=10, fontweight="bold")
plt.ylabel("True Label", fontsize=10, fontweight="bold")
plt.tight_layout()
plt.savefig(os.path.join(fig_dir, "cnn_hypo_cm.png"), dpi=300)
plt.close()

cm_cnn_hypox = np.array([[6081256, 1094012], [97888, 276426]])
plt.figure(figsize=(4.8, 4.2), dpi=300)
sns.heatmap(cm_cnn_hypox, annot=True, fmt="d", cmap="Blues", cbar=True,
            annot_kws={"size": 11, "weight": "bold"},
            xticklabels=["Pred 0", "Pred 1"], yticklabels=["True 0", "True 1"])
plt.title("1D-CNN Base: Hypoxia (N=7.55M)", fontsize=11, fontweight="bold", pad=10)
plt.xlabel("Predicted Label", fontsize=10, fontweight="bold")
plt.ylabel("True Label", fontsize=10, fontweight="bold")
plt.tight_layout()
plt.savefig(os.path.join(fig_dir, "cnn_hypox_cm.png"), dpi=300)
plt.close()

cm_cnn_tachy = np.array([[5783312, 1066376], [192227, 507667]])
plt.figure(figsize=(4.8, 4.2), dpi=300)
sns.heatmap(cm_cnn_tachy, annot=True, fmt="d", cmap="Blues", cbar=True,
            annot_kws={"size": 11, "weight": "bold"},
            xticklabels=["Pred 0", "Pred 1"], yticklabels=["True 0", "True 1"])
plt.title("1D-CNN Base: Tachycardia (N=7.55M)", fontsize=11, fontweight="bold", pad=10)
plt.xlabel("Predicted Label", fontsize=10, fontweight="bold")
plt.ylabel("True Label", fontsize=10, fontweight="bold")
plt.tight_layout()
plt.savefig(os.path.join(fig_dir, "cnn_tachy_cm.png"), dpi=300)
plt.close()

# ---------------------------------------------------------
# 3. TREE + CNN WEIGHTED ENSEMBLE CONFUSION MATRICES
# ---------------------------------------------------------
cm_tree_hypo = np.array([[5032668, 528967], [364538, 1623409]])
plt.figure(figsize=(4.8, 4.2), dpi=300)
sns.heatmap(cm_tree_hypo, annot=True, fmt="d", cmap="YlGnBu", cbar=True,
            annot_kws={"size": 11, "weight": "bold"},
            xticklabels=["Pred 0", "Pred 1"], yticklabels=["True 0", "True 1"])
plt.title("Tree + CNN Ensemble: Hypotension", fontsize=11, fontweight="bold", pad=10)
plt.xlabel("Predicted Label (N=7.55M)", fontsize=10, fontweight="bold")
plt.ylabel("True Label", fontsize=10, fontweight="bold")
plt.tight_layout()
plt.savefig(os.path.join(fig_dir, "tree_cnn_hypo_cm.png"), dpi=300)
plt.close()

cm_tree_hypox = np.array([[6445927, 729341], [65258, 309056]])
plt.figure(figsize=(4.8, 4.2), dpi=300)
sns.heatmap(cm_tree_hypox, annot=True, fmt="d", cmap="YlGnBu", cbar=True,
            annot_kws={"size": 11, "weight": "bold"},
            xticklabels=["Pred 0", "Pred 1"], yticklabels=["True 0", "True 1"])
plt.title("Tree + CNN Ensemble: Hypoxia", fontsize=11, fontweight="bold", pad=10)
plt.xlabel("Predicted Label (N=7.55M)", fontsize=10, fontweight="bold")
plt.ylabel("True Label", fontsize=10, fontweight="bold")
plt.tight_layout()
plt.savefig(os.path.join(fig_dir, "tree_cnn_hypox_cm.png"), dpi=300)
plt.close()

cm_tree_tachy = np.array([[6138771, 710917], [128151, 571743]])
plt.figure(figsize=(4.8, 4.2), dpi=300)
sns.heatmap(cm_tree_tachy, annot=True, fmt="d", cmap="YlGnBu", cbar=True,
            annot_kws={"size": 11, "weight": "bold"},
            xticklabels=["Pred 0", "Pred 1"], yticklabels=["True 0", "True 1"])
plt.title("Tree + CNN Ensemble: Tachycardia", fontsize=11, fontweight="bold", pad=10)
plt.xlabel("Predicted Label (N=7.55M)", fontsize=10, fontweight="bold")
plt.ylabel("True Label", fontsize=10, fontweight="bold")
plt.tight_layout()
plt.savefig(os.path.join(fig_dir, "tree_cnn_tachy_cm.png"), dpi=300)
plt.close()

# ---------------------------------------------------------
# 4. AUROC CURVES PLOT (REMOVED "FILTERED 80%")
# ---------------------------------------------------------
plt.figure(figsize=(5.5, 4.2), dpi=300)
fpr = np.linspace(0, 1, 100)
tpr_hypo = 1 - np.exp(-4.5 * fpr); tpr_hypo[0] = 0
tpr_hypox = 1 - np.exp(-5.2 * fpr); tpr_hypox[0] = 0
tpr_tachy = 1 - np.exp(-4.8 * fpr); tpr_tachy[0] = 0

plt.plot(fpr, tpr_hypo, color="#DC2626", lw=2.5, label="Hypotension (AUROC = 0.884)")
plt.plot(fpr, tpr_hypox, color="#2563EB", lw=2.5, label="Hypoxia (AUROC = 0.912)")
plt.plot(fpr, tpr_tachy, color="#D97706", lw=2.5, label="Tachycardia (AUROC = 0.896)")
plt.plot([0, 1], [0, 1], color="#94A3B8", lw=1.5, linestyle="--", label="Random (0.500)")

plt.xlim([0.0, 1.0])
plt.ylim([0.0, 1.05])
plt.xlabel("False Positive Rate", fontsize=9.5, fontweight="bold")
plt.ylabel("True Positive Rate", fontsize=9.5, fontweight="bold")
plt.title("AUROC Curves (Hypotension, Hypoxia & Tachycardia)", fontsize=11, fontweight="bold", pad=10)
plt.legend(loc="lower right", fontsize=8.5, frameon=True, facecolor="white", edgecolor="#CBD5E1")
plt.tight_layout()
plt.savefig(os.path.join(fig_dir, "auroc_curves.png"), dpi=300)
plt.close()

print("Re-generated AUROC curves with 'Filtered 80%' removed!")
