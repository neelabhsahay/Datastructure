# Define a default value for FILE if not provided
FILE ?= default_file.cc
LOC ?= $(PWD)
BUILD_DIR ?= $(LOC)/../../build
OBJ_DIR = $(BUILD_DIR)/obj
BIN_DIR = $(BUILD_DIR)/bin
LIB_DIR = $(BUILD_DIR)/libs

CC := g++ 
CXX_FLAGS := -Wall -fPIC # -fPIC is crucial for shared libraries
LD_FLAGS =
LIB_FLAGS = -shared -dIS_LIB

SRCS := $(subst :, ,$(FILE))

OBJS := $(patsubst %.cc,$(OBJ_DIR)/%.o,$(SRCS))
EXEC_NAME := $(patsubst %.cc,%, $(firstword $(SRCS)))
LIB_NAME := $(patsubst %.cc,%.so, $(firstword $(SRCS)))
LIB = $(LIB_DIR)/$(LIB_NAME)
EXEC =  $(BIN_DIR)/$(EXEC_NAME)

# Rule to compile the specified file
$(OBJS): $(OBJ_DIR)/%.o: %.cc
	$(CC) $(CXX_FLAGS) -c $< -o $@

# Rule to link the object file
$(EXEC): $(OBJS)
	$(CC) $^ -o $@

# Rule to make library
$(LIB): $(OBJS)
	$(CC) $(LIB_FLAGS) $< -o $@

$(LIB_DIR):
	@mkdir -p $(LIB_DIR)

$(BIN_DIR):
	@mkdir -p $(BIN_DIR)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

.SILENT:
.PHONY: clean run build lib

build:
	@make $(BIN_DIR)
	@make $(OBJ_DIR)
	@make $(EXEC)

run: build
	@$(EXEC)

lib:
	@make $(LIB_DIR)
	@make $(OBJ_DIR)
	@make $(LIB)

clean:
	@echo $(BUILD_DIR)
	@echo $(EXEC)
	@echo $(OBJ)
	@rm -rf $(OBJ_DIR) $(BIN_DIR) $(LIB_DIR)
