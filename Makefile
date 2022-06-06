all: functions.o
	gcc functions.o main.c -o main
	clear

functions.o: functions.h
	gcc -c functions.c
	clear

run:
	./main

clean:
	rm -rf *.o main

make start:
	make clean
	make
	clear
	make run
