P=euler
OBJECTS= euler.o
CFLAGS= -g -Wall
LDLIBS=
CC=c99


$(P):$(OBJECTS)

clean:
	rm $(OBJECTS) $(P)
