# Compiler settings
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2 -Iinclude

# Paths
SRC_DIR = src
SCRIPT_DIR = scripts
DATA_DIR = data

# Files
TARGET = compbot
SRC = $(SRC_DIR)/main.cpp $(SRC_DIR)/Robot.cpp
OBJ = $(SRC:.cpp=.o)

# Default rule
all: $(TARGET)

# Build target
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

# Compile .cpp → .o inside src/
$(SRC_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run simulation + visualization
run: $(TARGET)
	./$(TARGET)
	python3 $(SCRIPT_DIR)/animate_path.py

# Clean build
clean:
	rm -f $(OBJ) $(TARGET)
