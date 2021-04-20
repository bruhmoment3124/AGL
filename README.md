# Overview

#### win(char *title, int width, int height)
creates window, with a title and a specific width and height

#### begin(int hex)
takes a hexadecimal value and clears the screen that color

#### end()
ends drawing

#### dline(int x1, int y1, int x2, int y1, int hex)
takes first x position, first y position, second x position, second y position, color
and then draws a line

#### drect(int x, int y, int w, int h, int hex)
takes x position, y position, width, height, color and draws a rectangle 

#### dcirc(int x, int y, int radx, rady, int hex)
takes x position, y position, radius x, radius y, color and draws a circle or oval

# [Examples](https://github.com/bruhmoment3124/AGL/tree/main/examples)
```
#include <AGL.h>

main()
{
  	win("Hello, World!", 1000, 500);
	begin(0xFFFFFF); /*set window color*/
		
	end();
}
```
