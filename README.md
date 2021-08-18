# Overview

## agl.h

#### agl_window(char *title, int width, int height)
creates window, with a title and a specific width and height

#### agl_takeinput()
begins taking input (see example 2 on how to use)

#### agl_begin(int hex)
takes a hexadecimal value and clears the screen that color

#### agl_end()
ends drawing

#### agl_line(int x1, int y1, int x2, int y1, int hex)
takes first x position, first y position, second x position, second y position, color
and then draws a line

#### agl_rectangle(int x, int y, int w, int h, int hex)
takes x position, y position, width, height, color and draws a rectangle 

#### agl_circle(int x, int y, int radx, rady, int hex)
takes x position, y position, radius x, radius y, color and draws a circle or oval

## aglkey.h

NOTE: aglkey.h HAS to be included AFTER agl.h

#### agl_keyhold(int key)
takes ascii keycode and returns value until key is released

# [Examples](https://github.com/bruhmoment3124/AGL/tree/main/examples)
There are 2 ways to make a window with AGL, first is:
```
#include <AGL/agl.h>

main()
{
  	agl_window("Hello, World!", 1000, 500);
	agl_begin(0xFFFFFF); /*set window color*/
		
	agl_end();
}
```
the pros for the first method is:
- It's simple and easy to use
```
#include <AGL/agl.h>

main()
{
  	GLFWwindow *win = agl_window("Hello, World!", 1000, 500);
	while(!glfwWindowShouldClose(win))
	{
		agl_begin(0xFFFFFF); /*set window color*/
		agl_takeinput();
	}
	glfwTerminate();
}
```
the pros for the second method is:
- Allows for input
- Can be used with GLFW

the first method uses AGL as a standalone graphics library and the second uses AGL in conjunction with GLFW

# Build
All you need to build AGL is glfw3
