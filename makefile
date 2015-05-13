CC = gcc
CFLAGS = -g -Wall -std=gnu89
LDFLAGS = -lm

SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
EXEC = sd-project

%.o: %.c
	$(CC) -o $@  -c $< $(CFLAGS) 

$(EXEC): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)

clean:
	rm $(OBJS) $(EXEC)
