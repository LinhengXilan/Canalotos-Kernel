# @file Makefile
# @author LinhengXilan
# @version 0.0.0.5
# @date 2026-6-25

.SILENT:
MAKEFLAGS += --no-print-directory

export WORK_PATH := $(shell pwd)/
export BINARY_PATH := $(WORK_PATH)/Binary/
export INTERMEDIATE_PATH := $(WORK_PATH)Intermediate/

export C++ := g++
export ASM := nasm
export MAKE := make
export AR := ar
export LD := ld
export OBJCOPY := objcopy

export C++_FLAGS := -std=c++20 \
					-m64 \
					-c \
					-O2 \
					-nostdlib -fno-builtin -nostdinc -ffreestanding\
					-I$(WORK_PATH)Include \
					-Wall -Wextra -Werror \
					-fno-stack-protector \
					-fno-exceptions -fno-rtti \
					-fno-threadsafe-statics \
					-fno-use-cxa-atexit
export ASM_FLAGS := 
export AR_FLAGS := rcs
export LD_FLAGS := -T Kernel.lds \
				   -nostdlib \
				   -Map kernel.map
export OBJCOPY_FLAGS := -O binary \
						-S \
						-g				

SUBDIRS := Shell Kernel Lib Graphics Memory Bootloader

.PHONT: all clean

all: $(SUBDIRS)
	printf "\tLD\t%s\n" Kernel.elf
	$(LD) --start-group $(sort $(shell find $(INTERMEDIATE_PATH) -type f -name '*.a')) --end-group $(LD_FLAGS) -o $(INTERMEDIATE_PATH)Kernel.elf
	printf "\tOBJCOPY\t%s\n" Kernel.bin
	$(OBJCOPY) $(OBJCOPY_FLAGS) $(INTERMEDIATE_PATH)Kernel.elf $(BINARY_PATH)Kernel.bin
$(SUBDIRS): mkdir
	$(MAKE) -C $@

mkdir:
	mkdir -p $(BINARY_PATH)
	mkdir -p $(INTERMEDIATE_PATH)

clean:
	rm -rf $(INTERMEDIATE_PATH)
	rm -rf $(BINARY_PATH)