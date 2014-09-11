CC = gcc
CFLAGS = -g -Wall 

arrayList: main.o

main.o: arrayList.h 

arrayList.o: arrayList.h

clean:
	rm -f *.o
