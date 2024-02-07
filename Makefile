CXX := g++
CXXFLAGS := -Wall -Wextra -Werror -Wuninitialized -pedantic -std=c++17 -fPIC
SRC_DIR := src
INC_DIR := inc
SRCS := $(wildcard $(SRC_DIR)/*.cc)
HDRS := $(wildcard $(INC_DIR)/*.h)
LIBRARY := libgeometric.so
TARGET := my_prog
OBJ_DIR := obj
BIN_DIR := bin

OBJS := $(patsubst $(SRC_DIR)/%.cc,$(OBJ_DIR)/%.o,$(SRCS))

$(TARGET): $(BIN_DIR)/$(LIBRARY) main.cc
	export LD_LIBRARY_PATH=./$(BIN_DIR):$$LD_LIBRARY_PATH && \
	$(CXX) $(CXXFLAGS) -I$(INC_DIR) -L$(BIN_DIR) main.cc -lgeometric -o $(BIN_DIR)/$(TARGET)

$(BIN_DIR)/$(LIBRARY): $(OBJS) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -shared -o $(BIN_DIR)/$(LIBRARY) $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cc $(HDRS) | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -I$(INC_DIR) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

.PHONY: clean
clean:
	rm -rf $(OBJ_DIR)

.PHONY: fclean
fclean: clean
	rm -rf $(BIN_DIR)

.PHONY: rebuild
rebuild: fclean $(TARGET)

$(OBJS): $(HDRS)

.DEFAULT_GOAL := $(TARGET)
