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
void find_particles(int *e1, int *e2, Element elements[], int maxnum) {
	// first element
	printf("Enter the atomic number of an element: ");
	scanf("%d", e1);
	while (*e1 < 1 || *e1 > maxnum)	{ // must be a known particle
		printf("Your input was invalid. Enter the atomic number of a known element (between 1 and 118): ");
		scanf("%d", e1);
	}
	printf("%s\n", elements[(*e1) - 1].element);

	// second element	
	printf("Enter the atomic number of an element: ");
	scanf("%d", e2);
	while (*e2 < 1 || *e2 > maxnum)	{ // must be a known particle
		printf("Your input was invalid. Enter the atomic number of a known element (between 1 and 118): ");
		scanf("%d", e2);
	}
	printf("%s\n", elements[*e2 - 1].element);
	printf("\n");
}

// moves the particles around
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
		usleep(pausetime);

		// if particles touching (collided), break
		distance = 2*sqrt(x_offset*x_offset + y_offset*y_offset) - circle_radius1 - circle_radius2;
		if (distance <= 0) {
			return;
		}
	}

}

// make a filled-in circle
void make_particle(float xstart, float ystart, float radius) {
	float i = 0.;
	for (i = 0; i <= radius; i += 2) {
		gfx_circle(xstart, ystart, i);
	}
}

// make big new element
void new_particle(int new_element, Element elements[], float xstart, float ystart, int maxnum) {
	gfx_clear();
	gfx_flush();
	gfx_color(rand() % 256, rand() % 256, rand() % 256);

	int radius = 4 * sqrt(new_element);
	make_particle(xstart, ystart, radius);
	gfx_flush();
	usleep(1000000);
	
	if (new_element > maxnum) {
		printf("You created a new element with %d protons! The largest known element it will eventually decay into is Oganesson, with 118 protons. \n", new_element);
	} else {
		char *ele = malloc(20*sizeof(char));
		int i;
		for (i = 0; i < strlen(elements[new_element - 1].element); i++) {
			if (isalpha((elements[new_element - 1].element)[i])) {
				ele[i] = (elements[new_element - 1].element)[i];
			} else {
				break;
			}
		}
		printf("You created %s, also known as %s, which has an atomic number of %d!\n", ele, elements[new_element-1].symbol, new_element);
	}
}
