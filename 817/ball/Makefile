CC  = g++
C	  = cpp
H	  = h

CFLAGS    = -g -std=c++11

ifeq ("$(shell uname)", "Darwin")
  LDFLAGS     = -framework Foundation -framework GLUT -framework OpenGL -lm
else
  ifeq ("$(shell uname)", "Linux")
    LDFLAGS     = -lglut -lGL -lGLU -lm
  endif
endif

HFILES = Model.${H} View.${H} Vector.${H} Utility.${H} Camera.${H}
OFILES = Model.o View.o Vector.o Utility.o Camera.o

PROJECT   = ball

${PROJECT}: ${PROJECT}.o ${OFILES}
	${CC} ${CFLAGS} -o ${PROJECT} ${PROJECT}.o ${OFILES} ${LDFLAGS}

${PROJECT}.o:   ${PROJECT}.${C} ${HFILES} ${INCFLAGS}
	${CC} ${CFLAGS} -c ${INCFLAGS} ${PROJECT}.${C}

Model.o: Model.${C} Model.${H} Vector.${H} Utility.${H}
	${CC} $(CFLAGS) -c Model.${C}

View.o: View.${C} View.${H} Camera.${H} Vector.${H} Utility.${H}
	${CC} $(CFLAGS) -c View.${C}

Camera.o: Camera.${C} Camera.${H} Vector.${H} Utility.${H}
	${CC} $(CFLAGS) -c Camera.${C}

Vector.o: Vector.${C} Vector.${H} Utility.${H}
	${CC} $(CFLAGS) -c Vector.${C}

Utility.o: Utility.${C} Utility.${H}
	${CC} $(CFLAGS) -c Utility.${C}

clean:
	rm -f core.* *.o *~ .DS_Store ${PROJECT}
