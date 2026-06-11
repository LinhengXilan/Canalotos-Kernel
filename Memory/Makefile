# @file Memory/Makefile
# @author LinhengXilan
# @version 0.0.0.4
# @date 2026-6-8

.SILENT:

COMPONENT := Memory
COMPONENT_INTERMEDIATE_PATH := $(INTERMEDIATE_PATH)$(COMPONENT)/

SOURCES := $(shell find . -type f -name '*.cpp' -printf '%P\n')
OBJECTS := $(SOURCES:.cpp=.o)
SHELL_OBJECTS := $(addprefix $(COMPONENT)/, $(OBJECTS))
INTERMEDIATE_OBJECTS := $(addprefix $(COMPONENT_INTERMEDIATE_PATH), $(OBJECTS))

TARGET := $(COMPONENT).a

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(INTERMEDIATE_OBJECTS)
	printf "\tAR\t%s\n" $(TARGET)
	$(AR) $(AR_FLAGS) $(COMPONENT_INTERMEDIATE_PATH)$@ $^

$(COMPONENT_INTERMEDIATE_PATH)%.o: %.cpp
	mkdir -p $(dir $@)
	printf "\tC++\t%s\n" $(COMPONENT)/$(patsubst $(COMPONENT_INTERMEDIATE_PATH)%,%,$(@))
	$(C++) $< $(C++_FLAGS) -o $@