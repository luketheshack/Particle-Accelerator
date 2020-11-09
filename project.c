// Luke Marushack
// Fundamentals of Computing : Lab #11
// project.c

#include "projfunc.h"

int main() {

	char *fn = malloc(20);
	fn = "elements.csv";
	FILE *fp = fopen(fn, "r+");

	

	while (1) {
		if feof(fp) break;
	}

	return 0;
}
