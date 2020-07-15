sources = main.c search.c ${method}.c ../${grpath}/graph.c ../common/${container}.c
target = search
CC = gcc
CCFLAG = -g -Wall -fsanitize=address

all:
	$(CC) $(CCFLAG) $(sources) -o $(target)

clean:
	rm -f $(target)