project: project.o projfunc.o
	gcc project.o projfunc.o gfx.o -lX11 -lm -o project

project.o: projfunc.h project.c
	gcc -c project.c -o project.o

projfunc.o: projfunc.h projfunc.c
	gcc -c projfunc.c -o projfunc.o

clean:
	rm project.o
	rm projfunc.o
	rm project
