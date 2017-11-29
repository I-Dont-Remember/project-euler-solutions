CFLAGS= -g -Wall -I lib/
LDFLAGS=
LDLIBS= -lm
CC=c99
ALL_EXECUTABLES := $(shell find . -type f ! -name '*.*' -name 'p[0-9]*')

ifndef p
$(error p variable is not set)
endif

.PHONY: force

p$(p): force lib/common.o
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ src/p$(p).c lib/common.o $(LDLIBS)

lib/common.o:

create:
	@[ ! -f src/p$(p).c ] && cp template src/p$(p).c && echo "Made new problem p$(p).c"

clean:
	rm $(ALL_EXECUTABLES)
