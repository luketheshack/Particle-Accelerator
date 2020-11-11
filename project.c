// Luke Marushack
// Fundamentals of Computing : Lab #11
// project.c

#include "projfunc.h"

int main() {

	char *fn = malloc(20);
	fn = "elements.csv";
	FILE *fp = fopen(fn, "r+");
	
	int maxnum = 118; // current known number of elements
	Element elements[maxnum];
	int size = get_elements(fp, elements);

	int i;
	for (i = 0; i < size; i++) {
		printf("%d\n", elements[i].atomic);
	}
	
	return 0;
}
