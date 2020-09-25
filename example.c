/*
	A simple example of using the gfx library.
	CSE 20211
	9/7/2011
	by Prof. Thain
	Modified and expanded by Mr. Savoie 16/Sept/2020
*/
#include <stdio.h>
#include <stdlib.h>
#include "gfx.h"
void mySetup();
void makeStuff(int d, int b, int r);
void gridder(int d, int b, int r);
void middleBox(int d, int b, int r);
char sizeDecide(char n);
#define Gsize 2 
#define ysize 239 * Gsize
#define xsize 239 * Gsize
//default dimensions
#define dim 3 
#define buff 4 * Gsize
#define res 77 * Gsize

int	d, b, r; // dimensions, border, resolution

int main()
{

	mySetup();
	char c;
  while (1) { // Wait for the user to press a character, to set size.
		c = sizeDecide(c = gfx_wait());
		if (c != 'q' && c != '0') {
			r = r * Gsize;
			b = b * Gsize;
			makeStuff(d, b, r);
		}		
		if (c == 'q') break; // Quit if it is the letter q.
	}
	return 0;

}

void makeStuff(int d, int b, int r) {

	gfx_clear();
	gridder(d, b, r);
	middleBox(d, b, r);
	gfx_flush();

}

void middleBox(int d, int b, int r) {

	for (int i = 0; i < d; i++) {
		for (int j = 0; j < d; j++) {
			for (int k = 1 + b; k < r - 1; k++) {
				for (int l = 1 + b;l < r - 1; l++) {
						int yesNo;
						if ((yesNo = rand() % 2) == 1) {
							gfx_point(i * r + b + k, j * r + b + l);
						};
					//gfx_point(i * r + b + k * (k++)/16, j * r + b + l);
				}
			}
		}
	} 

}

void gridder(int d, int b, int r) {

	for (int i = 0; i < d; i++) {
		for (int j = 0; j < d; j++) {
			gfx_line(i * r + b,
							 j * r + b,
							 i * r + b,
							 j * r + r + b);
			gfx_line(i * r + b,
							 j * r + b,
							 i * r + r + b,
							 j * r + b);
		}
	} 
	gfx_line(b,
					 r * d + b,
					 r * d + b, 
					 r * d + b);
	gfx_line(r * d + b,
					 r * d + b,
					 r * d + b,
					 b);

}

char sizeDecide(char c) {

	if (c == '3') {
		d = 3;
		b = 4;
		r = 77;
	} else if (c == '5') {
		d = 5;
		b = 2;
		r = 47;
	} else if (c == '7') {
		d = 7;
		b = 4;
		r = 33;
	} else if (c == '9') {
		d = 9;
		b = 7;
		r = 25;
	} else if (c == 'b') {
		d = 11;
		b = 4;
		r = 21;
	} else if (c == 'q') {
		return 'q';
	} else {
		return '0';
	}

}

void mySetup() {

	gfx_open(xsize, ysize, "Example Graphics Program");
	gfx_color(0, 200, 100);
	//make stuff with default parameters from #define variables
	makeStuff(dim, buff, res);

}