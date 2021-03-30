#include <math.h>
#include <GLFW/glfw3.h>

GLFWwindow *window; /*create window object*/
static int sw; /*screen width*/
static int sh; /*screen height*/

/****************
/window functions
/***************/

/*creates window*/
void win(char *title, int width, int height)
{
	glfwInit(); /*initialize glfw*/
  window = glfwCreateWindow(width, height, title, NULL, NULL); /*create a window with glfw*/
	glfwMakeContextCurrent(window);
	
	/*set screen variables for use in other functions*/
	sw = width;
	sh = height;
}

/*window loop*/
int loop(int hex) /*background values*/
{
	glfwPollEvents(); /*input*/
 	if(input(GLFW_KEY_ESCAPE)) return 0; /*exit the program*/
	
	/*convert hex*/
	float r, g, b;
	r = hex >> 16;
	g = (hex & 0x00ff00) >> 8;
	b = (hex & 0x0000ff);
	
	/*convert float*/
	r /= 255.0f; /*red*/
	g /= 255.0f; /*green*/
	b /= 255.0f; /*blue*/
	glClearColor(r, g, b, 255); /*clear window specified color*/
	glClear(GL_COLOR_BUFFER_BIT); /*clear screen*/
}

/*end drawing*/
void end()
{
	glfwSwapBuffers(window);
}

/*****************
/drawing functions
/****************/

/*draw a line*/
void dline(float x1, float y1, float x2, float y2, int hex)
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
		glVertex2f(x1, y1);
		glVertex2f(x2, y2);
		glColor3f(r, g, b);
	glEnd();
}

/*draw a rectangle*/
void drect(float x, float y, float w, float h, int hex)
{
	/*color values*/
	float r, g, b;
	r = hex >> 16;
	g = (hex & 0x00ff00) >> 8;
	b = (hex & 0x0000ff);
	
	r /= 255.0f;
	g /= 255.0f;
	b /= 255.0f;
	
	/*convert opengl float values to standard X and Y*/
	x /= (float)sw;
  y /= (float)sh;
	w = (w * 2) / (float)sw;
	h = (h * 2) / (float)sh;
	
	glBegin(GL_QUADS);
		glVertex2f(x, y);
		glVertex2f(x + w, y);
		glVertex2f(x + w, y - h);
		glVertex2f(x, y - h);
		glVertex2f(x + w, y - h);
		glColor3f(r, g, b);
	glEnd();
}

/*draw a circle*/
void dcirc(float x, float y, float rad, int hex)
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
	rad /= (float)sw;
	
	float theta;
	glBegin(GL_POLYGON);
		int i;
		for(i=0; i<360; i++)
		{
			theta = i * 3.142 / 180;
			glVertex2f(x + rad * cos(theta), y + rad * sin(theta));
			glColor3f(r, g, b);
		}
	glEnd();
}

/******************
/keyboard functions
/*****************/

int input(int key)
{
	int state = glfwGetKey(window, key);
	return state;
}