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
int getMouseTile(int c, int x, int y);
void incrementTile(int i);
void cursorShift(int x, int y);
#define ysize 297 
#define xsize 297 + 27 + 27 + 27 
#define dim 11 
#define buff 0
#define res 27 
#define defaultNextTile 0
int R, C, mx, my;
char T = '2';

void mySetup()
{
  gfx_open(xsize, ysize, "Example Graphics Program");
  gfx_color(0, 200, 100);
  makeStuff(dim, buff, res);
  morphTile(T, 2, 12); // extra side-tile
}
int main()
{
  mySetup();
  char c, t;
  while (1) { // Wait for the user to press a character.
    if (c = gfx_event_waiting()) { 
      mx = gfx_xpos();
      my = gfx_ypos();
      c = gfx_wait();
      if (c == 1) {
        incrementTile(0);
        getMouseTile(1, mx, my);
        morphTile(T, 2, 12);
      }
      if (c == 'q') break; // Quit if it is the letter q.
    } 
    gfx_color(0, 255, 0);
    cursorShift(mx, my);
    gfx_flush();
  }
  return 0;
}
int getMouseTile(int c, int x, int y) 
{
  if (c == 1) { // one is mouse left-click
    int r = 1;
    for (int j = 1; j <= 11; j++) {
      for (int i = 1; i <= 11; i++) {
        if (x < res * i && y < res * j && x > res * (i - 1) && y > res * (j - 1)) {
          C = i - 1; R = j - 1; return r;
        }
      r++;
      }
    }
    if (x < res * 13  && y < res * 3 && x > res * 12  && y > res * 2) { r = 1; C = 12; R = 2; return -1;}
  } // else handle arrow keys?
  return 0;
}
void incrementTile(int i)
{
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
void morphTile(char nextTile, int row, int col) 
{
  int kolor, tile;
  tile = nextTile;
  for (int k = 0; k < res; k++) {
    for (int l = 0; l < res; l++) {
      kolor = getTilePixel(tile, k, l);
      gfx_color(0, kolor * 200, kolor * 100);
      gfx_point(col * res + l + buff, row * res + k + buff);
    }
  }
}
void makeStuff(int d, int b, int r) 
{
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
  gfx_line(25, 25, 25, 298 - 27);
  gfx_line(26, 25, 298 - 27, 25);
  gfx_line(298 - 27, 26, 298 - 27, 298 - 27);
  gfx_line(298 - 27, 298 - 27, 26, 298 - 27);

  //side pane divider
  gfx_color(200, 150, 100);
  gfx_line(297, 0, 297, 297);
}
int fetchTile(int mapNum, int index) 
{
  int x;
  x = gm[index][mapNum];
  return x; 
}
int getTilePixel(int tile, int k, int l) 
{
  if (tile == '1') {
    return 0;
  } else {
    int x;
    switch (tile) {
      case '0': x = dot[k][l]; break; 
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
int myLastTile = 0;
void cursorShift(int x, int y) 
{
  int myTileNow = getMouseTile(1, x, y);
  if (myTileNow != myLastTile) {
    makeStuff(dim, buff, res);
    gfx_color(0,0,200);
    gfx_line(C*res-1,R*res-1,C*res+res-1,R*res-1);
    gfx_line(C*res-1,R*res-1,C*res-1,R*res+res-1);
    gfx_line(C*res+res,R*res+res-1,C*res+res,R*res-1);
    gfx_line(C*res+res,R*res+res,C*res-1,R*res+res);
    morphTile(T, 2, 12);
  }
  myLastTile = myTileNow; 
}
