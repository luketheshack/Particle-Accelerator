project: project.o projfunc.o
	gcc project.o projfunc.o -o project

projfunc.o: projfunc.h projfunc.c
	gcc projfunc.c -o projfunc.o

project.o: projfunc.h project.c
	gcc project.c -o project.o

clean:
	rm *.o
	rm project
