/*
	A simple example of using the gfx library.
	CSE 20211
	9/7/2011
	by Prof. Thain
	Modified and expanded by Mr. Savoie Oct/2020
*/
#include <stdio.h>
#include <stdlib.h>
#include "./lib/gfx.h"
#include "./lib/tiles.c"
#include "./lib/gm.c"

void mySetup();
void makeStuff(int d, int b, int r);
void morphTile();
int getTilePixel(int map, int k, int l);
int fetchTile(int mapNum, int index);
int getMouseTile(int c);

#define ysize 297 
#define xsize 298 
//default dimensions
#define dim 11 
#define buff 0
#define res 27 

int main()
{

	mySetup();
	char c, t;
  while (1) { // Wait for the user to press a character, to set size.
		c = gfx_wait();
		t = getMouseTile(c);	
		if (c == 'q') break; // Quit if it is the letter q.
		if (t == 1) {
			gfx_color(100, 250, 10);
			gfx_line(10, 10, 100, 100);
			gfx_flush();
			morphTile();
		}
	}
	return 0;

}

void mySetup() {

	gfx_open(xsize, ysize, "Example Graphics Program");
	gfx_color(0, 200, 100);
	makeStuff(dim, buff, res);

}

void morphTile() {

	//gfx_clear();
	int kolor;
	tile = '4';
	for (int k = 0; k < res; k++) {
		for (int l = 0; l < res; l++) {
			kolor = getTilePixel(tile, k, l);
			gfx_color(0, kolor * 200, kolor * 100);
			gfx_point(0 * res + l + buff, 0 * res + k + buff);
		}
	}
	gfx_flush();

}

void makeStuff(int d, int b, int r) {

	gfx_clear();
	int masterCount = 0;
	int kolor, tile;
	for (int i = 0; i < d; i++) {
		for (int j = 0; j < d; j++) {
			tile = fetchTile(1, masterCount);
			masterCount++;
			for (int k = 0; k < r; k++) {
				for (int l = 0; l < r; l++) {
					kolor = getTilePixel(tile, k, l);
					gfx_color(0, kolor * 200, kolor * 100);
					gfx_point(j * r + l + b, i * r + k + b);
				}
			}
		}
	}	
	gfx_color(200, 0, 0);
	gfx_line(28, 28, 28, 297 - 28);
	gfx_line(28, 28, 297 - 28, 28);
	gfx_line(297 - 28, 28, 297 - 28, 297 - 28);
	gfx_line(297 - 28, 297 - 28, 28, 297 - 28);
	gfx_flush();

}

int fetchTile(int mapNum, int index) {

	int x;
	x = gm[index][mapNum];
	return x; 

}

int getTilePixel(int tile, int k, int l) {

	if (tile == '1') {
		return 0;
	} else {
		int x;
		switch (tile) {
			case '2': x = tl[k][l]; break;
			case '3': x = tr[k][l]; break;
			case '4': x = bl[k][l]; break;
			case '5': x = br[k][l]; break;
			case '6': x = ss[k][l]; break;
			case '7': x = bs[k][l]; break;
			case '8': x = vm[k][l]; break;
			case '9': x = vl[k][l]; break;
			case 'A': x = vr[k][l]; break;
			case 'B': x = hm[k][l]; break;
			case 'C': x = ht[k][l]; break;
			case 'D': x = hb[k][l]; break;
			case 'E': x = tt[k][l]; break;
			default: x = 1; break;
		}
		return x;
	}

}
int getMouseTile(int c) {

	if (c == 1) {
		int x = gfx_ypos();
		int y = gfx_xpos();
		if (x < 10 && y < 10) {
			return 1;	
		}
	}
	return 0;

}

