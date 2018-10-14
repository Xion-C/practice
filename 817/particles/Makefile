CXX  = g++

CXXFLAGS    = -g -std=c++11

ifeq ("$(shell uname)", "Darwin")
  LDFLAGS     = -framework Foundation -framework GLUT -framework OpenGL -lm
else
  ifeq ("$(shell uname)", "Linux")
    LDFLAGS     = -lglut -lGL -lGLU -lm
  endif
endif

HEADERS = $(shell find . -regex ".*\.h" | tr '\n' ' ')
OBJECTS = $(shell find . -regex ".*\.cpp" -printf "%P " | sed 's/.cpp/.o/g')

EXEC = particles

%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $< -o $@

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} -o $@ ${OBJECTS} ${LDFLAGS}

clean:
	rm -f core.* *.o *~ .DS_Store ${EXEC}
