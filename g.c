/*
	A simple example of using the gfx library.
	CSE 20211
	9/7/2011
	by Prof. Thain
*/
#include <stdio.h>
#include "gfx.h"
void mySetup();
void makeStuff(int d, int b, int r);
void gridder(int d, int b, int r);
char sizeDecide(char n);
#define Gsize 2 
#define ysize 240 * Gsize
#define xsize 240 * Gsize
//default dimensions
#define dim 3 
#define buff 4 * Gsize
#define res 77 * Gsize

int	rr, dd, bb; // resolution, dimensions, border

int main()
{
	mySetup();
	char c;
  while (1) { // Wait for the user to press a character.
		c = sizeDecide(c = gfx_wait());
		if (c != 'q' && c != '0') {
			rr = rr * Gsize;
			bb = bb * Gsize;
			makeStuff(dd, bb, rr);
		}		
		if (c == 'q') break; // Quit if it is the letter q.
	}
	return 0;
}

void makeStuff(int d, int b, int r) {

	gfx_clear();
	gridder(d, b, r);
	gfx_flush();

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
		rr = 77;
		bb = 4;
		dd = 3;
	} else if (c == '5') {
		rr = 47;
		bb = 2;
		dd = 5;
	} else if (c == '7') {
		rr = 33;
		bb = 4;
		dd = 7;
	} else if (c == '9') {
		rr = 25;
		bb = 7;
		dd = 9;
	} else if (c == 'b') {
		rr = 21;
		bb = 4;
		dd = 11;
	} else if (c == 'q') {
		return 'q';
	} else {
		return '0';
	}
}

void mySetup() {

	gfx_open(xsize, ysize, "Example Graphics Program");
	gfx_color(0, 200, 100);
	makeStuff(dim, buff, res);

}
