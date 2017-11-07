## Compiler
CC=g++
## Linker
LD=$(CC)
## Flags
CPPFLAGS = -Wall -g -DLINUX -std=c++11
LFLAGS = -lglut -L/usr/lib -L/usr/X11R6/lib -lXi -lXmu -lGL -lGLU -lm

###
# TARGETS = $(PROGFILES:.cpp=)
#
# PROGFILES = \
#         main.cpp \
# 				lines.cpp
#         $(NULL)
#
# targets default: $(TARGETS)
#
# $(PROGFILES:.cpp=): main.o lines.cpp
# 	$(CC) -o run main.o ${LFLAGS}
###

OBJS = \
	cgmath.o \
	viewer.o \
	main.o
EXEC = run

%.o: %.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@

$(EXEC): $(OBJS)
	$(CC) -o $@ $(OBJS) $(LFLAGS)

# main.o: main.cpp

depend :
	makedepend ${PROGFILES}

clean:
	rm -f run *.o

# DO NOT DELETE
