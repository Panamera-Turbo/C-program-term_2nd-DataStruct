sources = *.c
target = bstfind
CCFLAG = -g -Wall -fsanitize=address
CC = gcc

all:
	$(CC) $(CCFLAG) $(sources) -o $(target)

clean:
	rm -f $(target)