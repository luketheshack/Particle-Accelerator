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

void move_particle(int element1, int element2, Element elements[], float xstart, float ystart, float radians, float rotation_radius) {
	float x_offset = 0, y_offset = 0;
	int pausetime = 5000;
	int circle_radius1 = 5 * sqrt(elements[element1-1].atomic);
	int circle_radius2 = 5 * sqrt(elements[element2-1].atomic);

	int distance;

	while (1) {
		gfx_clear();

		gfx_color((elements[element1-1].atomic * (rand() % 100)) % 256, (elements[element1-1].atomic * (rand() % 100) + 100) % 256, (elements[element1-1].atomic * (rand() % 100) + 200) % 256);
		make_particle(xstart + x_offset, ystart + y_offset, circle_radius1);
		
		gfx_color((elements[element2-1].atomic * (rand() % 100)) % 256, (elements[element2-1].atomic * (rand() % 100) + 100) % 256, (elements[element2-1].atomic * (rand() % 100) + 200) % 256);
		make_particle(xstart - x_offset, ystart - y_offset, circle_radius2);
		
		gfx_flush();

		x_offset = rotation_radius*cos(radians);
		y_offset = rotation_radius*sin(radians);

		radians += 0.01;
		rotation_radius *= 0.998;
		if (pausetime > 1000) pausetime -= 5;
		// will need to change pausetime parameters, tune this thing
		usleep(pausetime);

		// if particles touching (collided), break
		distance = 2*sqrt(x_offset*x_offset + y_offset*y_offset) - circle_radius1 - circle_radius2;
		if (distance <= 0) {
			return;
		}
	}

}

void make_particle(float xstart, float ystart, float radius) {
	float i = 0.;
	for (i = 0; i <= radius; i += 2) {
		gfx_circle(xstart, ystart, i);
	}
}

void new_particle(int new_element, Element elements[], float xstart, float ystart) {
	gfx_clear();
	gfx_flush();
	gfx_color(rand() % 256, rand() % 256, rand() % 256);

	int radius = 4 * sqrt(new_element);
	make_particle(xstart, ystart, radius);
	gfx_flush();
	usleep(1000000);
	// quit, print out info, and go again
	if (new_element > 118) {
		printf("You created a new element with %d protons! The largest known element it will eventually decay into is Oganesson, with 118 protons. \n", new_element);
	} else {
		printf("%s\n", elements[new_element - 1].element);
		printf("You created %s, also known as %s, which has an atomic number of %d!\n", elements[new_element - 1].element, elements[new_element-1].symbol, new_element);
	}

}
