GIT_VERSION := $(shell git describe --all --long HEAD)

.PRECIOUS: *.map

# Earlier versions of the Raspberry Pi image only had riscv32-gcc
ifneq (,$(wildcard /usr/bin/riscv32-unknown-elf-gcc))
TRGT       ?= riscv32-unknown-elf-
else
TRGT       ?= riscv64-unknown-elf-
endif

CC         := $(TRGT)gcc
CXX        := $(TRGT)g++
OBJCOPY    := $(TRGT)objcopy

RM         := rm -rf
COPY       := cp -a
PATH_SEP   := /

ifeq ($(OS),Windows_NT)
COPY       := copy
RM         := del
PATH_SEP   := \\
endif

PACKAGE    := riscv-notifier
BASE_DIR   := .
LD_DIR     := $(BASE_DIR)/ld
LDSCRIPT   := $(BASE_DIR)/ld/linker.ld
ADD_CFLAGS := -I$(BASE_DIR)/include -D__vexriscv__ -march=rv32i  -mabi=ilp32
ADD_LFLAGS := -Xlinker -Map=$(PACKAGE).map

LDSCRIPTS  := $(LDSCRIPT) $(LD_DIR)/output_format.ld $(LD_DIR)/regions.ld
SRC_DIR    := $(BASE_DIR)/src
THIRD_PARTY := $(BASE_DIR)/third_party
DBG_CFLAGS := -ggdb -g -DDEBUG -Wall
DBG_LFLAGS := -ggdb -g -Wall
CFLAGS     := $(ADD_CFLAGS) \
			  -Wall -Wextra \
			  -ffunction-sections -fdata-sections -fno-common \
			  -fomit-frame-pointer -Os \
			  -march=rv32i \
			  -DGIT_VERSION=u\"$(GIT_VERSION)\" -std=gnu11
CXXFLAGS   := $(CFLAGS) -std=c++11 -fno-rtti -fno-exceptions
LFLAGS     := $(CFLAGS) $(ADD_LFLAGS) -L$(LD_DIR) \
			  -nostartfiles \
			  -Wl,--gc-sections \
			  -Wl,--no-warn-mismatch \
			  -Wl,--script=$(LDSCRIPT) \
			  -Wl,--build-id=none

OBJ_DIR    := .obj

CSOURCES   := $(wildcard $(SRC_DIR)/*.c) $(wildcard $(THIRD_PARTY)/libbase/*.c) $(wildcard $(THIRD_PARTY)/*.c)
CPPSOURCES := $(wildcard $(SRC_DIR)/*.cpp) $(wildcard $(THIRD_PARTY)/libbase/*.cpp) $(wildcard $(THIRD_PARTY)/*.cpp)
ASOURCES   := $(wildcard $(SRC_DIR)/*.S) $(wildcard $(THIRD_PARTY)/libbase/*.S) $(wildcard $(THIRD_PARTY)/*.S)
COBJS      := $(addprefix $(OBJ_DIR)/, $(notdir $(CSOURCES:.c=.o)))
CXXOBJS    := $(addprefix $(OBJ_DIR)/, $(notdir $(CPPSOURCES:.cpp=.o)))
AOBJS      := $(addprefix $(OBJ_DIR)/, $(notdir $(ASOURCES:.S=.o)))
OBJECTS    := $(COBJS) $(CXXOBJS) $(AOBJS)
VPATH      := $(SRC_DIR) $(THIRD_PARTY) $(THIRD_PARTY)/libbase

QUIET      := @

ALL        := all
TARGET     := $(PACKAGE).elf
CLEAN      := clean

$(ALL): $(TARGET) $(PACKAGE).bin $(PACKAGE).ihex $(PACKAGE).dfu

$(OBJECTS): | $(OBJ_DIR)

$(TARGET): $(OBJECTS) $(LDSCRIPTS)
	$(QUIET) echo "  LD       $@"
	$(QUIET) $(CC) $(OBJECTS) $(LFLAGS) -o $@

$(PACKAGE).bin: $(TARGET)
	$(QUIET) echo "  OBJCOPY  $@"
	$(QUIET) $(OBJCOPY) -O binary $(TARGET) $@

$(PACKAGE).dfu: $(PACKAGE).bin
	$(QUIET) echo "  DFU      $@"
	$(QUIET) $(COPY) $(PACKAGE).bin $@
	$(QUIET) dfu-suffix -v 1209 -p 70b1 -a $@

$(PACKAGE).ihex: $(TARGET)
	$(QUIET) echo "  IHEX     $(PACKAGE).ihex"
	$(QUIET) $(OBJCOPY) -O ihex $(TARGET) $@

$(DEBUG): CFLAGS += $(DBG_CFLAGS)
$(DEBUG): LFLAGS += $(DBG_LFLAGS)
CFLAGS += $(DBG_CFLAGS)
LFLAGS += $(DBG_LFLAGS)
$(DEBUG): $(TARGET)

$(OBJ_DIR):
	$(QUIET) mkdir $(OBJ_DIR)

$(COBJS) : $(OBJ_DIR)/%.o : %.c $(BASE_DIR)/Makefile
	$(QUIET) echo "  CC       $<	$(notdir $@)"
	$(QUIET) $(CC) -c $< $(CFLAGS) -o $@ -MMD

$(OBJ_DIR)/%.o: %.cpp
	$(QUIET) echo "  CXX      $<	$(notdir $@)"
	$(QUIET) $(CXX) -c $< $(CXXFLAGS) -o $@ -MMD

$(OBJ_DIR)/%.o: %.S
	$(QUIET) echo "  AS       $<	$(notdir $@)"
	$(QUIET) $(CC) -x assembler-with-cpp -c $< $(CFLAGS) -o $@ -MMD

.PHONY: clean

clean:
	$(QUIET) echo "  RM      $(subst /,$(PATH_SEP),$(wildcard $(OBJ_DIR)/*.d))"
	-$(QUIET) $(RM) $(subst /,$(PATH_SEP),$(wildcard $(OBJ_DIR)/*.d))
	$(QUIET) echo "  RM      $(subst /,$(PATH_SEP),$(wildcard $(OBJ_DIR)/*.d))"
	-$(QUIET) $(RM) $(subst /,$(PATH_SEP),$(wildcard $(OBJ_DIR)/*.o))
	$(QUIET) echo "  RM      $(TARGET) $(PACKAGE).bin $(PACKAGE).symbol $(PACKAGE).ihex $(PACKAGE).dfu"
	-$(QUIET) $(RM) $(TARGET) $(PACKAGE).bin $(PACKAGE).symbol $(PACKAGE).ihex $(PACKAGE).dfu

reboot:
	wishbone-tool 0xe0006000 0xac

include $(wildcard $(OBJ_DIR)/*.d)
