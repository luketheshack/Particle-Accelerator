project: project.o projfunc.o
	gcc project.o projfunc.o -o project

project.o: projfunc.h project.c
	gcc -c project.c -o project.o

projfunc.o: projfunc.h projfunc.c
	gcc -c projfunc.c -o projfunc.o

clean:
	rm *.o
	rm project
