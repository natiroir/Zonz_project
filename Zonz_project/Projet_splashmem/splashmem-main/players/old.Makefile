SRCS=$(wildcard *.c)
OBJS=$(SRCS:.c=.o)
CFLAGS= -Wall -I../src -fPIC
LDFLAGS=
NAME=example

all: $(OBJS)
	gcc -shared -o p1.so player1.o
	gcc -shared -o p2.so player2.o
	gcc -shared -o p3.so player3.o
	gcc -shared -o p4.so player4.o

clean:
	rm -f $(OBJS)
	rm -f *.so
