build_all: final_pr library
	gcc -o result main.o -L. -lprint

final_pr:
	gcc -c main.c

library: translate
	ar cr libprint.a fio.o img.o

translate::
	gcc -c fio.c
translate::
	gcc -c img.c


clean_all:
	rm -f *.o *.a *.so print


