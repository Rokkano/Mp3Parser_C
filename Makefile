CC=gcc -g -fsanitize=address
CFLAGS=-Wextra -Werror
LDFLAGS =-lcurl
LDLIBS =



SRC= lib/fopen.c src/core/main.c src/Query/string/stringQuery.c src/Command/command.c
OBJ= ${SRC:.c=.o}

all: main
main:
	$(CC) -o main $(OBJ) $(CFLAGS) $(LDFLAGS)
reforge: clean forge main
forge: $(OBJ)
clean:
	rm -f $(OBJ) main
	
	
	
