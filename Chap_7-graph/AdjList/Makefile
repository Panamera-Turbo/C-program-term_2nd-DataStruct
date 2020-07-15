sources = *.c
target = graph
CC = gcc
CCFLAG = -g -Wall -fsanitize=address

all:
	cp ../common/main_graph.c .
	$(CC) $(CCFLAG) $(sources) -o $(target)

clean:
	rm -f $(target) main_graph.c