# Compiler and compiler flags
CXX = g++
CXXFLAGS = -Wall -std=c++11

# Define the executable files 
MAIN = main
TEST = test

# Define the source directory and object directory
SRC_DIR = .
OBJ_DIR = obj

# Source file listings
ALL_SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
MAIN_SOURCES = $(filter-out $(SRC_DIR)/test.cpp, $(ALL_SOURCES))
TEST_SOURCES = $(filter-out $(SRC_DIR)/main.cpp, $(ALL_SOURCES))

MAIN_OBJECTS = $(MAIN_SOURCES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
TEST_OBJECTS = $(TEST_SOURCES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# Default target
all: $(MAIN) $(TEST)

# Link the program
$(MAIN): $(MAIN_OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(MAIN) $(MAIN_OBJECTS)

$(TEST): $(TEST_OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TEST) $(TEST_OBJECTS)

# Compile the source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up
clean:
	rm -rf $(OBJ_DIR) $(MAIN) $(TEST)

.PHONY: all clean
