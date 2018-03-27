CXX = clang++

# Warnings frequently signal eventual errors:
CXXFLAGS=-g -W -Wall -std=c++11 -Weffc++ -Wextra -pedantic -O0

OBJS = main.o pointer.o

EXEC = run

# automatic variables: $< - the name of the prerequisite of
# the rule; $@ - the name of the target of the rule

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# - means skip to next one if failed
clean:
	-rm -rf $(OBJS)
	-rm -rf $(EXEC)
