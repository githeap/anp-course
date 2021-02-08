### If you wish to use extra libraries (math.h for instance),
### add their flags here (-lm in our case) in the "LIBS" variable.
CC = clang
LIBS = -lm

###
CFLAGS  = -std=c99
CFLAGS += -g
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -Wmissing-declarations
CFLAGS += -DUNITY_SUPPORT_64

ASANFLAGS  = -fsanitize=address
ASANFLAGS += -fno-common
ASANFLAGS += -fno-omit-frame-pointer


test: tests.out
	@./tests.out

memcheck: test.c unity/*.c unity/*.h funcs.h funcs.c
	@echo Compiling $@
	@$(CC) $(ASANFLAGS) $(CFLAGS) test.c unity/unity.c funcs.c -o memcheck.out $(LIBS)
	@./memcheck.out
	@echo "Memory check passed"

clean:
	rm -rf *.o *.out *.out.dSYM

tests.out: test.c unity/*.c unity/*.h funcs.h funcs.c
	@echo Compiling $@
	@$(CC) $(CFLAGS) test.c unity/unity.c funcs.c  -o tests.out $(LIBS)

main: main.c funcs.h funcs.c
	@echo Compiling $@
	@$(CC) $(CFLAGS) main.c funcs.c  -o main.out $(LIBS)
