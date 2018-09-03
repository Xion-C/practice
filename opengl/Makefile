CC = gcc
CXX = g++

CXXFLAGS = -g -W -Wall -std=c++11 -Weffc++ -Wextra -pedantic -O0 -lglfw -lGL -lGLU -lX11 -lpthread -lXrandr -lXi -ldl -lm

LIBDIR = -L/usr/lib -L/usr/X11R6/lib

LIBS = -lpthread -lglfw -lGLU -lGL -lX11 -lXrandr -lXi -ldl -lm

# include flags
INC = \
  -I./glad/include \
  -I/opt/local/include

OBJS = \
  $(shell find . -regex ".*\.cpp" -printf "%P " | sed 's/.cpp/.o/g') \
  glad/src/glad.o

EXEC = run

# automatic variables:
# $< - the name of the prerequisite of the rule;
# $@ - the name of the target of the rule

.c.o:
	$(CC) -c $(INC) -g -o $@ $<

%.o: %.cpp
	$(CXX) -c $(INC) $(CXXFLAGS) $< -o $@

$(EXEC): $(OBJS)
	@echo $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(INC) $(OBJS) $(LIBDIR) $(LIBS) $(LDFLAGS)

clean:
	rm -rf $(OBJS)
	rm -rf $(EXEC)
