CXX = g++

CXXFLAGS = -g -W -Wall -std=c++11 -Weffc++ -Wextra -pedantic -O0

OBJS = $(shell find . -regex ".*\.cpp" -printf "%P " | sed 's/.cpp/.o/g')

EXEC = run

# automatic variables: $< - the name of the prerequisite of
# the rule; $@ - the name of the target of the rule

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS) $(LDFLAGS)

clean:
	rm -rf $(OBJS)
	rm -rf $(EXEC)
