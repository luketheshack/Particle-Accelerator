// Luke Marushack
// Fundamentals of Computing : Lab #11
// projfunc.c

#include "projfunc.h"
#include "gfx.h"

// read particles in from data file and puts them in array
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

// gets new particles to be collided from user
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

void move_particle(int element, Element elements[], float xstart, float ystart, float radians, float rotation_radius) {
	float x_offset = 0, y_offset = 0;
	int pausetime = 5000;
	gfx_color((elements[element-1].atomic * 100) % 256, (elements[element-1].atomic * 100 + 100) % 256, (elements[element-1].atomic * 100 + 200) % 256);
	int circle_radius = 10 * sqrt(elements[element-1].atomic);
	while (1) {
		gfx_clear();

		gfx_circle(xstart + x_offset, ystart + y_offset, circle_radius);
		gfx_flush();

		x_offset = rotation_radius*cos(radians);
		y_offset = rotation_radius*sin(radians);

		radians += 0.01;
		//rotation_radius;
		pausetime -= 10;
		usleep(pausetime);
	}

}
