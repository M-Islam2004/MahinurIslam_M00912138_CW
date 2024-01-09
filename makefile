CXX = g++
CXXFLAGS = -Wall -Wextra

# List of source files
SRCS = main.cpp
TEST_SRCS = test.cpp

# List of object files
OBJS = $(SRCS:.cpp=.o)
TEST_OBJS = $(TEST_SRCS:.cpp=.o)

# Executable names
PROGRAM = library
TEST_PROGRAM = test_program

CATCH_INCLUDE = catch.hpp

# Targets
all: $(PROGRAM) $(TEST_PROGRAM)

$(PROGRAM): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(PROGRAM)

$(TEST_PROGRAM): $(filter-out main.o, $(OBJS)) $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) $(filter-out main.o, $(OBJS)) $(TEST_OBJS) -o $(TEST_PROGRAM) -I $(CATCH_INCLUDE)

test: $(TEST_PROGRAM)
	./$(TEST_PROGRAM)

clean:
	rm -f $(OBJS) $(TEST_OBJS) $(PROGRAM) $(TEST_PROGRAM)

