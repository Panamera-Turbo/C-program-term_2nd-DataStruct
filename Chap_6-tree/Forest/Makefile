sources = *.c ../CSTree/BiTree.c ../CSTree/CSTree.c
target = forest
CC = gcc
CCFLAG = -g -Wall -fsanitize=address

all:
	$(CC) $(CCFLAG) $(sources) -o $(target)

clean:
	rm -f $(target)