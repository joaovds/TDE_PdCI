all: functions.o
	gcc functions.o main.c -o main

functions.o: functions.h
	gcc -c functions.c

run:
	./main

clean:
	rm -rf *.o main
