# Define a default value for FILE if not provided
FILE ?= default_file.cc
LOC ?= $(PWD)
BUILD_DIR ?= $(LOC)/../../build
OBJ_DIR = $(BUILD_DIR)/obj
BIN_DIR = $(BUILD_DIR)/bin

CC := g++ 
CXX_FLAGS := -Wall -g
LDFLAGS =

SRCS := $(subst :, ,$(FILE))

OBJS := $(patsubst %.cc,$(OBJ_DIR)/%.o,$(SRCS))
EXEC_NAME := $(patsubst %.cc,%, $(firstword $(SRCS)))
EXEC =  $(BIN_DIR)/$(EXEC_NAME)

# Rule to compile the specified file
$(OBJS): $(OBJ_DIR)/%.o: %.cc
	$(CC) $(CXX_FLAGS) -c $< -o $@

# Rule to link the object file
$(EXEC): $(OBJS)
	$(CC) $^ -o $@

$(BIN_DIR):
	@mkdir -p $(BIN_DIR)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

.SILENT:
.PHONY: clean run build

build:
	@make $(BIN_DIR)
	@make $(OBJ_DIR)
	@make $(EXEC)

run: build
	@$(EXEC)

clean:
	@echo $(BUILD_DIR)
	@echo $(EXEC)
	@echo $(OBJ)
	@rm -rf $(OBJ_DIR) $(BIN_DIR)
