CC = gcc 
FLAGS = -Wall -g

all: txtfind isort 


txtfind: mainfind.o txtfind.o
	$(CC) $(FLAGS) -o txtfind mainfind.o txtfind.o 

mainfind.o: txtfind.c txtfind.h
	$(CC) $(FLAGS) -c mainfind.c 

txtfind.o: txtfind.c txtfind.h
	$(CC) $(FLAGS)  -c txtfind.c


isort: mainsort.o isort.o
	$(CC) $(FLAGS) -o isort mainsort.o isort.o 

mainsort.o: mainsort.c isort.h
	$(CC) $(FLAGS) -c mainsort.c 

isort.o: isort.c isort.h
	$(CC) $(FLAGS) -c isort.c 



.PHONY: clean all

clean:
	rm -f *.o  txtfind isort
