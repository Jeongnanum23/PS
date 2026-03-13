program: main.o class.o
	gcc -o program main.o class.o

main.o: main.c class.h
	gcc -c main.c

class.o: class.c class.h
	gcc -c class.c

clean:
	rm -f *.o program