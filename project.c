// Luke Marushack
// Fundamentals of Computing : Lab #11
// project.c

#include "projfunc.h"
#include "gfx.h"

int main() {

	char *fn = malloc(20);
	fn = "elements.csv";
	FILE *fp = fopen(fn, "r+");
	
	int maxnum = 118; // current known number of elements
	Element elements[maxnum];
	int size = get_elements(fp, elements);
	int e1, e2; // element 1 and element 2
	char c;

	int wd = 1000, ht = 1000;

	do {
		find_particles( &e1, &e2, elements);
		printf("Preparing particles...\n");
		usleep(1000000);
		gfx_open(wd, ht, "Particle Accelerator");
		gfx_point(2, 3);
		usleep(1000000);
	} while (1 > 2);

	return 0;
}
