CC = gcc
CFLAGS = -g -Wall -ansi

SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
EXEC = sd-project

%.o: %.c
	$(CC) -o $@  -c $< $(CFLAGS) 

$(EXEC): $(OBJS)
	$(CC) -o $@ $^

clean:
	rm $(OBJS) $(EXEC)
