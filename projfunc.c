// Luke Marushack
// Fundamentals of Computing : Lab #11
// projfunc.c

#include "projfunc.h"


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
