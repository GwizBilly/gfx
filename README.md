# gfx
Project for using a simple C graphics library on a Linux machine (Raspberry Pi or WSL/VcXsrv in my case).

I mostly develop on Windows10 using the Windows Subystem for Linux. At the time of writing this, setting up on windows means you have to install an x11 server like "VcXsrv" and have it running in the background when you launch your graphical app.

To install x11:
```
sudo apt install libx11-dev
```

To compile:
```
gcc example.c ./lib/gfx.c -o example -lX11 -lm
```
To compile my current project:
```
gcc mapMaker.c ./lib/tiles.c ./lib/gm.c ./lib/gfx.c -o makeMap -lX11 -lm
```
Note that the 'X' in the -lX11 is capitalized.

To run:
```
./example
```

# Links to orginal resource

https://www3.nd.edu/~dthain/courses/cse20211/fall2013/gfx/

This simple graphics library was written by Douglas Thain and is licensed under a Creative Commons Attribution 4.0 International License.  https://creativecommons.org/licenses/by/4.0/

# Modifications made to the "simple graphics library"

I have added mouse pointer events that don't require a button press or key press.
The original library was designed so that:

"gfx_xpos() and gfx_ypos return the X and Y coordinates, respectively, of the mouse pointer when the last key or button was pressed."

I added a MotionNotify event in the gfx_event_waiting() function of gfx.c library, by adding "PointerMotionMask" to the masks parameter of the XSelectInput() function:
```
XSelectInput(gfx_display, gfx_window, StructureNotifyMask|KeyPressMask|ButtonPressMask|PointerMotionMask);
```
 Instructions and documentation for adding X11 MotionNotify events were found here: https://tronche.com/gui/x/xlib/events/keyboard-pointer/keyboard-pointer.html
 
