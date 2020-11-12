/*
  A simple example of using the gfx library.
  CSE 20211
  9/7/2011
  by Prof. Thain
  Modified and expanded by Mr. Savoie Oct/2020-Nov2020
*/
#include <stdio.h>
#include <stdlib.h>
#include "./lib/gfx.h"
#include "./lib/tiles.c"
#include "./lib/gm.c"
void mySetup();
void makeStuff(int d, int b, int r);
void morphTile(char nextTile, int row, int col);
int getTilePixel(int map, int k, int l);
int fetchTile(int mapNum, int index);
int getMouseTile(int c);
void incrementTile();
#define ysize 297 
#define xsize 297 
#define dim 11 
#define buff 0
#define res 27 
#define defaultNextTile 0
int R,C;
char T = '2';
int main()
{
  mySetup();
  char c, t;
  while (1) { // Wait for the user to press a character, to set size.
    c = gfx_wait();
    if (c == 'q') break; // Quit if it is the letter q.
    if (t = getMouseTile(c) > 0) {
      incrementTile();
      morphTile(T, R, C);
    }
  }
  return 0;
}
void incrementTile() {
  if (T == '2') {
    T = '3';
  } else if (T == '3') {
    T = '4';
  } else if (T == '4') {
    T = '5';
  } else if (T == '5') {
    T = '6';
  } else if (T == '6') {
    T = '7';
  } else if (T == '7') {
    T = '8';
  } else if (T == '8') {
    T = '9';
  } else if (T == '9') {
    T = 'A';
  } else if (T == 'A') {
    T = 'B';
  } else if (T == 'B') {
    T = 'C';
  } else if (T == 'C') {
    T = 'D';
  } else if (T == 'D') {
    T = 'E';
  } else if (T == 'E') {
    T = '1';
  } else if (T == '1') {
    T = '2';
  }
}
void mySetup() {
  gfx_open(xsize, ysize, "Example Graphics Program");
  gfx_color(0, 200, 100);
  makeStuff(dim, buff, res);
}
void morphTile(char nextTile, int row, int col) {
  int kolor, tile;
  tile = nextTile;
  for (int k = 0; k < res; k++) {
    for (int l = 0; l < res; l++) {
      kolor = getTilePixel(tile, k, l);
      gfx_color(0, kolor * 200, kolor * 100);
      gfx_point(col * res + l + buff, row * res + k + buff);
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
  if (c == 1) { // one is mouse left-click
    int x = gfx_xpos();
    int y = gfx_ypos();
    int r = 0;
    if (x < res * 1  && y < res * 1 && x > res * 0  && y > res * 0) { r = 1; C = 0; R = 0;}
    if (x < res * 2  && y < res * 1 && x > res * 1  && y > res * 0) { r = 2; C = 1; R = 0;}
    if (x < res * 3  && y < res * 1 && x > res * 2  && y > res * 0) { r = 3; C = 2; R = 0;}
    if (x < res * 4  && y < res * 1 && x > res * 3  && y > res * 0) { r = 4; C = 3; R = 0;}
    if (x < res * 5  && y < res * 1 && x > res * 4  && y > res * 0) { r = 5; C = 4; R = 0;}
    if (x < res * 6  && y < res * 1 && x > res * 5  && y > res * 0) { r = 6; C = 5; R = 0;}
    if (x < res * 7  && y < res * 1 && x > res * 6  && y > res * 0) { r = 7; C = 6; R = 0;}
    if (x < res * 8  && y < res * 1 && x > res * 7  && y > res * 0) { r = 8; C = 7; R = 0;}
    if (x < res * 9  && y < res * 1 && x > res * 8  && y > res * 0) { r = 9; C = 8; R = 0;}
    if (x < res * 10 && y < res * 1 && x > res * 9  && y > res * 0) { r = 10; C = 9; R = 0;}
    if (x < res * 11 && y < res * 1 && x > res * 10 && y > res * 0) { r = 11; C = 10; R = 0;}
    
    if (x < res * 1  && y < res * 2 && x > res * 0  && y > res * 1) { r = 12;C = 0; R = 1;}
    if (x < res * 2  && y < res * 2 && x > res * 1  && y > res * 1) { r = 13;C = 1; R = 1;}
    if (x < res * 3  && y < res * 2 && x > res * 2  && y > res * 1) { r = 14;C = 2; R = 1;}
    if (x < res * 4  && y < res * 2 && x > res * 3  && y > res * 1) { r = 15;C = 3; R = 1;}
    if (x < res * 5  && y < res * 2 && x > res * 4  && y > res * 1) { r = 16;C = 4; R = 1;}
    if (x < res * 6  && y < res * 2 && x > res * 5  && y > res * 1) { r = 17;C = 5; R = 1;}
    if (x < res * 7  && y < res * 2 && x > res * 6  && y > res * 1) { r = 18;C = 6; R = 1;}
    if (x < res * 8  && y < res * 2 && x > res * 7  && y > res * 1) { r = 19;C = 7; R = 1;}
    if (x < res * 9  && y < res * 2 && x > res * 8  && y > res * 1) { r = 20;C = 8; R = 1;}
    if (x < res * 10 && y < res * 2 && x > res * 9  && y > res * 1) { r = 21;C = 9; R = 1;}
    if (x < res * 11 && y < res * 2 && x > res * 10 && y > res * 1) { r = 22;C = 10; R = 1;}

    if (x < res * 1  && y < res * 3 && x > res * 0  && y > res * 2) { r = 23;C = 0; R = 2;}
    if (x < res * 2  && y < res * 3 && x > res * 1  && y > res * 2) { r = 24;C = 1; R = 2;}
    if (x < res * 3  && y < res * 3 && x > res * 2  && y > res * 2) { r = 25;C = 2; R = 2;}
    if (x < res * 4  && y < res * 3 && x > res * 3  && y > res * 2) { r = 26;C = 3; R = 2;}
    if (x < res * 5  && y < res * 3 && x > res * 4  && y > res * 2) { r = 27;C = 4; R = 2;}
    if (x < res * 6  && y < res * 3 && x > res * 5  && y > res * 2) { r = 28;C = 5; R = 2;}
    if (x < res * 7  && y < res * 3 && x > res * 6  && y > res * 2) { r = 29;C = 6; R = 2;}
    if (x < res * 8  && y < res * 3 && x > res * 7  && y > res * 2) { r = 30;C = 7; R = 2;}
    if (x < res * 9  && y < res * 3 && x > res * 8  && y > res * 2) { r = 31;C = 8; R = 2;}
    if (x < res * 10 && y < res * 3 && x > res * 9  && y > res * 2) { r = 32;C = 9; R = 2;}
    if (x < res * 11 && y < res * 3 && x > res * 10 && y > res * 2) { r = 32;C = 10; R = 2;}

    if (x < res * 1  && y < res * 4 && x > res * 0  && y > res * 3) { r = 33;C = 0; R = 3;}
    if (x < res * 2  && y < res * 4 && x > res * 1  && y > res * 3) { r = 34;C = 1; R = 3;}
    if (x < res * 3  && y < res * 4 && x > res * 2  && y > res * 3) { r = 35;C = 2; R = 3;}
    if (x < res * 4  && y < res * 4 && x > res * 3  && y > res * 3) { r = 36;C = 3; R = 3;}
    if (x < res * 5  && y < res * 4 && x > res * 4  && y > res * 3) { r = 37;C = 4; R = 3;}
    if (x < res * 6  && y < res * 4 && x > res * 5  && y > res * 3) { r = 38;C = 5; R = 3;}
    if (x < res * 7  && y < res * 4 && x > res * 6  && y > res * 3) { r = 39;C = 6; R = 3;}
    if (x < res * 8  && y < res * 4 && x > res * 7  && y > res * 3) { r = 40;C = 7; R = 3;}
    if (x < res * 9  && y < res * 4 && x > res * 8  && y > res * 3) { r = 41;C = 8; R = 3;}
    if (x < res * 10 && y < res * 4 && x > res * 9  && y > res * 3) { r = 42;C = 9; R = 3;}
    if (x < res * 11 && y < res * 4 && x > res * 10 && y > res * 3) { r = 43;C = 10; R = 3;}

    if (x < res * 1  && y < res * 5 && x > res * 0  && y > res * 4) { r = 44;C = 0; R = 4;}
    if (x < res * 2  && y < res * 5 && x > res * 1  && y > res * 4) { r = 45;C = 1; R = 4;}
    if (x < res * 3  && y < res * 5 && x > res * 2  && y > res * 4) { r = 46;C = 2; R = 4;}
    if (x < res * 4  && y < res * 5 && x > res * 3  && y > res * 4) { r = 47;C = 3; R = 4;}
    if (x < res * 5  && y < res * 5 && x > res * 4  && y > res * 4) { r = 48;C = 4; R = 4;}
    if (x < res * 6  && y < res * 5 && x > res * 5  && y > res * 4) { r = 49;C = 5; R = 4;}
    if (x < res * 7  && y < res * 5 && x > res * 6  && y > res * 4) { r = 50;C = 6; R = 4;}
    if (x < res * 8  && y < res * 5 && x > res * 7  && y > res * 4) { r = 51;C = 7; R = 4;}
    if (x < res * 9  && y < res * 5 && x > res * 8  && y > res * 4) { r = 52;C = 8; R = 4;}
    if (x < res * 10 && y < res * 5 && x > res * 9  && y > res * 4) { r = 53;C = 9; R = 4;}
    if (x < res * 11 && y < res * 5 && x > res * 10 && y > res * 4) { r = 54;C = 10; R = 4;}

    if (x < res * 1  && y < res * 6 && x > res * 0  && y > res * 5) { r = 55;C = 0; R = 5;}
    if (x < res * 2  && y < res * 6 && x > res * 1  && y > res * 5) { r = 56;C = 1; R = 5;}
    if (x < res * 3  && y < res * 6 && x > res * 2  && y > res * 5) { r = 57;C = 2; R = 5;}
    if (x < res * 4  && y < res * 6 && x > res * 3  && y > res * 5) { r = 58;C = 3; R = 5;}
    if (x < res * 5  && y < res * 6 && x > res * 4  && y > res * 5) { r = 59;C = 4; R = 5;}
    if (x < res * 6  && y < res * 6 && x > res * 5  && y > res * 5) { r = 60;C = 5; R = 5;}
    if (x < res * 7  && y < res * 6 && x > res * 6  && y > res * 5) { r = 61;C = 6; R = 5;}
    if (x < res * 8  && y < res * 6 && x > res * 7  && y > res * 5) { r = 62;C = 7; R = 5;}
    if (x < res * 9  && y < res * 6 && x > res * 8  && y > res * 5) { r = 63;C = 8; R = 5;}
    if (x < res * 10 && y < res * 6 && x > res * 9  && y > res * 5) { r = 64;C = 9; R = 5;}
    if (x < res * 11 && y < res * 6 && x > res * 10 && y > res * 5) { r = 65;C = 10; R = 5;}

    if (x < res * 1  && y < res * 7 && x > res * 0  && y > res * 6) { r = 66;C = 0; R = 6;}
    if (x < res * 2  && y < res * 7 && x > res * 1  && y > res * 6) { r = 67;C = 1; R = 6;}
    if (x < res * 3  && y < res * 7 && x > res * 2  && y > res * 6) { r = 68;C = 2; R = 6;}
    if (x < res * 4  && y < res * 7 && x > res * 3  && y > res * 6) { r = 69;C = 3; R = 6;}
    if (x < res * 5  && y < res * 7 && x > res * 4  && y > res * 6) { r = 70;C = 4; R = 6;}
    if (x < res * 6  && y < res * 7 && x > res * 5  && y > res * 6) { r = 71;C = 5; R = 6;}
    if (x < res * 7  && y < res * 7 && x > res * 6  && y > res * 6) { r = 72;C = 6; R = 6;}
    if (x < res * 8  && y < res * 7 && x > res * 7  && y > res * 6) { r = 73;C = 7; R = 6;}
    if (x < res * 9  && y < res * 7 && x > res * 8  && y > res * 6) { r = 74;C = 8; R = 6;}
    if (x < res * 10 && y < res * 7 && x > res * 9  && y > res * 6) { r = 75;C = 9; R = 6;}
    if (x < res * 11 && y < res * 7 && x > res * 10 && y > res * 6) { r = 76;C = 10; R = 6;}

    if (x < res * 1  && y < res * 8 && x > res * 0  && y > res * 7) { r = 77;C = 0; R = 7;}
    if (x < res * 2  && y < res * 8 && x > res * 1  && y > res * 7) { r = 78;C = 1; R = 7;}
    if (x < res * 3  && y < res * 8 && x > res * 2  && y > res * 7) { r = 79;C = 2; R = 7;}
    if (x < res * 4  && y < res * 8 && x > res * 3  && y > res * 7) { r = 80;C = 3; R = 7;}
    if (x < res * 5  && y < res * 8 && x > res * 4  && y > res * 7) { r = 81;C = 4; R = 7;}
    if (x < res * 6  && y < res * 8 && x > res * 5  && y > res * 7) { r = 82;C = 5; R = 7;}
    if (x < res * 7  && y < res * 8 && x > res * 6  && y > res * 7) { r = 83;C = 6; R = 7;}
    if (x < res * 8  && y < res * 8 && x > res * 7  && y > res * 7) { r = 84;C = 7; R = 7;}
    if (x < res * 9  && y < res * 8 && x > res * 8  && y > res * 7) { r = 85;C = 8; R = 7;}
    if (x < res * 10 && y < res * 8 && x > res * 9  && y > res * 7) { r = 86;C = 9; R = 7;}
    if (x < res * 11 && y < res * 8 && x > res * 10 && y > res * 7) { r = 87;C = 10; R = 7;}
    
    if (x < res * 1  && y < res * 9 && x > res * 0  && y > res * 8) { r = 88;C = 0; R = 8;}
    if (x < res * 2  && y < res * 9 && x > res * 1  && y > res * 8) { r = 89;C = 1; R = 8;}
    if (x < res * 3  && y < res * 9 && x > res * 2  && y > res * 8) { r = 90;C = 2; R = 8;}
    if (x < res * 4  && y < res * 9 && x > res * 3  && y > res * 8) { r = 91;C = 3; R = 8;}
    if (x < res * 5  && y < res * 9 && x > res * 4  && y > res * 8) { r = 92;C = 4; R = 8;}
    if (x < res * 6  && y < res * 9 && x > res * 5  && y > res * 8) { r = 93;C = 5; R = 8;}
    if (x < res * 7  && y < res * 9 && x > res * 6  && y > res * 8) { r = 94;C = 6; R = 8;}
    if (x < res * 8  && y < res * 9 && x > res * 7  && y > res * 8) { r = 95;C = 7; R = 8;}
    if (x < res * 9  && y < res * 9 && x > res * 8  && y > res * 8) { r = 96;C = 8; R = 8;}
    if (x < res * 10 && y < res * 9 && x > res * 9  && y > res * 8) { r = 97;C = 9; R = 8;}
    if (x < res * 11 && y < res * 9 && x > res * 10 && y > res * 8) { r = 98;C = 10; R = 8;}

    if (x < res * 1  && y < res * 10 && x > res * 0  && y > res * 9) { r = 99;C = 0; R = 9;}
    if (x < res * 2  && y < res * 10 && x > res * 1  && y > res * 9) { r = 100;C = 1; R = 9;}
    if (x < res * 3  && y < res * 10 && x > res * 2  && y > res * 9) { r = 101;C = 2; R = 9;}
    if (x < res * 4  && y < res * 10 && x > res * 3  && y > res * 9) { r = 102;C = 3; R = 9;}
    if (x < res * 5  && y < res * 10 && x > res * 4  && y > res * 9) { r = 103;C = 4; R = 9;}
    if (x < res * 6  && y < res * 10 && x > res * 5  && y > res * 9) { r = 104;C = 5; R = 9;}
    if (x < res * 7  && y < res * 10 && x > res * 6  && y > res * 9) { r = 105;C = 6; R = 9;}
    if (x < res * 8  && y < res * 10 && x > res * 7  && y > res * 9) { r = 106;C = 7; R = 9;}
    if (x < res * 9  && y < res * 10 && x > res * 8  && y > res * 9) { r = 107;C = 8; R = 9;}
    if (x < res * 10 && y < res * 10 && x > res * 9  && y > res * 9) { r = 108;C = 9; R = 9;}
    if (x < res * 11 && y < res * 10 && x > res * 10 && y > res * 9) { r = 109;C = 10; R = 9;}

    if (x < res * 1  && y < res * 11 && x > res * 0  && y > res * 10) { r = 110;C = 0; R = 10;}
    if (x < res * 2  && y < res * 11&& x > res * 1  && y > res * 10) { r = 111;C = 1; R = 10;}
    if (x < res * 3  && y < res * 11&& x > res * 2  && y > res * 10) { r = 112;C = 2; R = 10;}
    if (x < res * 4  && y < res * 11&& x > res * 3  && y > res * 10) { r = 113;C = 3; R = 10;}
    if (x < res * 5  && y < res * 11&& x > res * 4  && y > res * 10) { r = 114;C = 4; R = 10;}
    if (x < res * 6  && y < res * 11&& x > res * 5  && y > res * 10) { r = 115;C = 5; R = 10;}
    if (x < res * 7  && y < res * 11&& x > res * 6  && y > res * 10) { r = 116;C = 6; R = 10;}
    if (x < res * 8  && y < res * 11&& x > res * 7  && y > res * 10) { r = 117;C = 7; R = 10;}
    if (x < res * 9  && y < res * 11&& x > res * 8  && y > res * 10) { r = 118;C = 8; R = 10;}
    if (x < res * 10 && y < res * 11&& x > res * 9  && y > res * 10) { r = 119;C = 9; R = 10;}
    if (x < res * 11 && y < res * 11&& x > res * 10 && y > res * 10) { r = 120;C = 10; R = 10;}

    return r;
  }
  return 0;
}
