// Luke Marushack
// Fundamentals of Computing : Lab #11
// projfunc.h

typedef struct {
	int atomic;
	char symbol[4];
	char element[20];	
} Element;

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// Takes the file and puts the data into an array of the struct Element
int get_elements(FILE *, Element []);
