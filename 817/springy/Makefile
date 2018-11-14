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
# OBJECTS = $(shell find . -regex ".*\.cpp" -printf "%P " | sed 's/.cpp/.o/g')

# https://hiltmon.com/blog/2015/08/01/simple-c-plus-plus-from-makefiles-to-xcode-builds/
SRCDIR = .
SRCEXT = cpp
SOURCES = $(shell find ${SRCDIR} -type f -name "*.${SRCEXT}")
BUILDDIR = .
OBJECTS = $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))

EXEC = springy

%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $< -o $@

# @echo "Objects: ${OBJECTS}"
${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} -o $@ ${OBJECTS} ${LDFLAGS}

clean:
	rm -f core.* *.o *~ .DS_Store ${EXEC}
