OBJECTS= src/p$(p).o
CFLAGS= -g -Wall
LDLIBS=
CC=c99
ALL_EXECUTABLES := $(shell find . -type f ! -name '*.*' -name 'p[0-9]*')

ifndef p
$(error p variable is not set)
endif

p$(p):
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ src/p$(p).c

create:
	@[ ! -f src/p$(p).c ] && cp template src/p$(p).c && echo "Made new problem p$(p).c"

clean:
	rm $(ALL_EXECUTABLES)
