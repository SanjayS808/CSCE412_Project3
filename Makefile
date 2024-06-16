# Define the compiler and compiler flags
CXX := g++
CXXFLAGS := -Wall -std=c++11 -Wno-unused-private-field

# Define the target executable and source files
TARGET := myprogram
SRCS := main.cpp Request.cpp RequestQueue.cpp WebServer.cpp LoadBalancer.cpp

# Define the object files (derived from source files)
OBJS := $(SRCS:.cpp=.o)

# Default rule to build the target
all: $(TARGET)

# Rule to build the target executable
$(TARGET): $(OBJS)
	$(CXX) -o $(TARGET) $(OBJS)

# Rule to build the object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(TARGET) $(OBJS)
	rm log.txt

.PHONY: all clean
