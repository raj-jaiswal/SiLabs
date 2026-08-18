# Makefile for Silicon Labs EFR32 Firmware & Native Simulator Test

CC ?= gcc
CFLAGS ?= -Wall -Wextra -O3 -Iinc
LDFLAGS ?= -lm

SRCS = src/vital_sign_engine.c src/main_native_sim.c
TARGET = efr32_sim

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $@ $(SRCS) $(LDFLAGS)

test: $(TARGET)
	./$(TARGET) ../patient_raw_data/patient_5882_1hz.csv || ./$(TARGET) patient_raw_data/patient_5882_1hz.csv

clean:
	rm -f $(TARGET) *.o

.PHONY: all test clean
