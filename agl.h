#include <math.h>
#include <GLFW/glfw3.h>

GLFWwindow *window; /*create window object*/
static int sw; /*screen width*/
static int sh; /*screen height*/

/****************
/window functions
/***************/

/*creates window*/
GLFWwindow *agl_window(char *title, int width, int height)
{
	glfwInit(); /*initialize glfw*/
 	window = glfwCreateWindow(width, height, title, NULL, NULL); /*create a window with glfw*/
	glfwMakeContextCurrent(window);
	
	/*set screen variables for use in other functions*/
	sw = width;
	sh = height;
	
	return window;
}

/*window loop*/
void agl_begin(int hex) /*background values*/
{	
	/*color values*/
	float r, g, b;
	r = hex >> 16;
	g = (hex & 0x00ff00) >> 8;
	b = (hex & 0x0000ff);
	r /= 255.0f; /*red*/
	g /= 255.0f; /*green*/
	b /= 255.0f; /*blue*/
	
	glClearColor(r, g, b, 255); /*clear window specified color*/
	glClear(GL_COLOR_BUFFER_BIT); /*clear screen*/
}

void agl_takeinput()
{
	glfwSwapBuffers(window);
	glfwPollEvents();
}

/*end drawing*/
void agl_end()
{
	glfwSwapBuffers(window);
	while(!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
	}
	glfwTerminate();
}

/*****************
/drawing functions
/****************/

/*draw a line*/
void agl_line(float x1, float y1, float x2, float y2, int hex)
{
	/*color values*/
	float r, g, b;
	r = hex >> 16;
	g = (hex & 0x00ff00) >> 8;
	b = (hex & 0x0000ff);
	r /= 255.0f; /*red*/
	g /= 255.0f; /*green*/
	b /= 255.0f; /*blue*/

	/*convert opengl float values to standard X and Y*/
	x1 /= (float)sw;
  	y1 /= (float)sh;
	x2 /= (float)sw;
	y2 /= (float)sh;
	
	glBegin(GL_LINE_STRIP);
		glColor3f(r, g, b);
		glVertex2f(x1, y1);
		glVertex2f(x2, y2);
	glEnd();
}

/*draw a rectangle*/
void agl_rectangle(float x, float y, float w, float h, int hex)
{
	/*color values*/
	float r, g, b;
	r = hex >> 16;
	g = (hex & 0x00ff00) >> 8;
	b = (hex & 0x0000ff);
	r /= 255.0f; /*red*/
	g /= 255.0f; /*green*/
	b /= 255.0f; /*blue*/
	
	/*convert opengl float values to standard X and Y*/
	x /= (float)sw;
  	y /= (float)sh;
	w = (w / (float)sw) * 2;
	h = (h / (float)sh) * 2;
	
	glBegin(GL_QUADS);
		glColor3f(r, g, b);
		glVertex2f(x, y);
		glVertex2f(x + w, y);
		glVertex2f(x + w, y - h);
		glVertex2f(x, y - h);
	glEnd();
}

/*draw a circle*/
void agl_circle(float x, float y, float radx, float rady, int hex)
{
	/*color values*/
	float r, g, b;
	r = hex >> 16;
	g = (hex & 0x00ff00) >> 8;
	b = (hex & 0x0000ff);
	r /= 255.0f; /*red*/
	g /= 255.0f; /*green*/
	b /= 255.0f; /*blue*/

	/*convert opengl float values to standard X and Y*/
	x /= (float)sw;
  	y /= (float)sh;
	radx /= (float)sw;
	rady /= (float)sh;
	
	float theta;
	glBegin(GL_POLYGON);
		glColor3f(r, g, b);
		int i;
		for(i=0; i<360; i++)
		{
			theta = i * 3.142 / 180;
			glVertex2f(x + radx * cos(theta), y + rady * sin(theta));
		}
	glEnd();
}
