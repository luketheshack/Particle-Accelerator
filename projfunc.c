// Luke Marushack
// Fundamentals of Computing : Lab #11
// projfunc.c

#include "projfunc.h"
#include "gfx.h"

int get_elements(FILE *fp, Element elements[]) {
	int i = 0;
	int maxsize = 30;
	char line[maxsize];

	while (1) {
		fgets(line, maxsize, fp);
		if (feof(fp)) break;
		elements[i].atomic = atoi(strtok(line, ","));
		strcpy(elements[i].symbol, strtok(NULL, ","));
		strcpy(elements[i].element, strtok(NULL, "\n"));
		++i;
	}
	return i;
}

void find_particles(int *e1, int *e2, Element elements[]) {
	// first element
	printf("Enter the atomic number of an element: ");
	scanf("%d", e1);
	while (*e1 < 1 || *e1 > 118)	{ // must be a known particle
		printf("That is invalid. Please try again. Enter the atomic number of a known element: ");
		scanf("%d", e1);
	}
	printf("%s\n", elements[(*e1) - 1].element);

	// second element	
	printf("Enter the atomic number of an element: ");
	scanf("%d", e2);
	while (*e2 < 1 || *e2 > 118)	{ // must be a known particle
		printf("That is invalid. Please try again. Enter the atomic number of a known element: ");
		scanf("%d", e2);
	}
	printf("%s\n", elements[*e2 - 1].element);
	printf("\n");
}
