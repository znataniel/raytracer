# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -O2 -std=c++20 -Iinclude -Isrc

# Directories
SRC_DIR = src
BUILD_DIR = build
STATIC_DIR = static
TARGET = $(BUILD_DIR)/raytracer

# Source and object files
SRCS = main.cpp $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(notdir $(SRCS)))

# Default target
all: $(TARGET)

# Link objects into executable
$(TARGET): $(OBJS) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

# Object files in build/ correspond to sources in src/ or root
$(BUILD_DIR)/%.o: %.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Add a separate rule for src/*.cpp
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Ensure build directory exists
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Run the program
run: $(TARGET)
	./$(TARGET)

# Clean build files
clean:
	rm -rf $(BUILD_DIR)

readme:
	convert $(BUILD_DIR)/out.ppm $(STATIC_DIR)/current.jpeg

.PHONY: all run clean
