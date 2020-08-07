SOURCE = kmp.c
CCFLAG = gcc -Wall -fsanitize=address 
TARGET = kmp

all:
	$(CCFLAG) $(SOURCE) -o $(TARGET)
clean:
	rm -f $(TARGET)