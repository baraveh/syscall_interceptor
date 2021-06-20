OBJS = main.o Interceptor.o
TARGET = main.out

CXX = g++
CFLAGS = -g -Wall

.SUFFIXES: .c .o 

all: main

main: Interceptor.o main.o 
	$(CXX) $(CFLAGS) -o main.out main.o Interceptor.o

.c.o:
	$(CXX) $(CFLAGS) -o $@ -c $<

clean:
	-rm -f $(OBJS) main.out