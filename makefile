CC= gcc -g
all : small_python

small_python:small-python.o intobject.o stringobject.o dictobject.o
	$(CC) -o small_python small-python.o intobject.o stringobject.o dictobject.o
	rm -f small-python.o intobject.o stringobject.o dictobject.o

small-python.o:small-python.c 
	$(CC) -o small-python.o -c small-python.c

intobject.o:intobject.c  
	$(CC) -o intobject.o  -c intobject.c

stringobject.o:stringobject.c 
	$(CC) -o stringobject.o  -c stringobject.c

dictobject.o:dictobject.c 
	$(CC) -o dictobject.o  -c dictobject.c

