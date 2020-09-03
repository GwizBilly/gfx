# gfx
Project for using a simple C graphics library on a Linux machine (Raspberry Pi in my case).

To install x11:
```
sudo apt install libx11-dev
```

To compile:
```
gcc example.c gfx.c -o example -lX11 -lm
```
Note that the 'X' in the -lX11 is capitalized.

To run:
```
./example
```

# Links to orginal resource

https://www3.nd.edu/~dthain/courses/cse20211/fall2013/gfx/

This simple graphics library was written by Douglas Thain and is licensed under a Creative Commons Attribution 4.0 International License.  https://creativecommons.org/licenses/by/4.0/
