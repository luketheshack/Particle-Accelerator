// Luke Marushack
// Fundamentals of Computing : Lab #11
// projfunc.h

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct {
	int atomic;
	char symbol[4];
	char element[20];	
} Element;

// Takes the file and puts the data into an array of the struct Element
int get_elements(FILE *, Element []);

//#endif
