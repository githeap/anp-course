### If you wish to use extra libraries (math.h for instance),
### add their flags here (-lm in our case) in the "LIBS" variable.
CC = clang-10
LIBS = -lm

###
CFLAGS  = -std=c99
CFLAGS += -g
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -pedantic
CFLAGS += -Werror
CFLAGS += -Wmissing-declarations
CFLAGS += -DUNITY_SUPPORT_64

ASANFLAGS  = -fsanitize=address
ASANFLAGS += -fno-common
ASANFLAGS += -fno-omit-frame-pointer

all: memcheck test

test: tests.out
	@./tests.out

memcheck: *.c unity/*.c unity/*.h *.h
	@echo Compiling $@
	@$(CC) $(ASANFLAGS) $(CFLAGS) *.c unity/unity.c -o memcheck.out $(LIBS)
	@./memcheck.out
	@echo "Memory check passed"

clean:
	rm -rf *.o *.out *.out.dSYM

tests.out: *.c unity/*.c unity/*.h *.h
	@echo Compiling $@
	@$(CC) $(CFLAGS) *.c unity/unity.c  -o tests.out $(LIBS)
