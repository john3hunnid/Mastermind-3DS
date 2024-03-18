main.o: main.s
	as -g main.s -o main.o
main: main.o
	ld -g main.o -o
	