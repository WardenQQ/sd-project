CC = gcc
CFLAGS = -g -Wall -std=gnu89
LDFLAGS = -lm

SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
EXEC = sd-project

%.o: %.c
	$(CC) -o $@  -c $< $(CFLAGS) 

all: server client

$(EXEC): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)

server: server.o gene.o genotype.o population.o map.o types_xdr.o procedures.o
	$(CC) -o $@ $^ $(LDFLAGS)

client: client.o gene.o genotype.o population.o map.o types_xdr.o procedures.o
	$(CC) -o $@ $^ $(LDFLAGS)

clean:
	rm $(OBJS) $(EXEC) server client server.o client.o


