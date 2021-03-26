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
  if(input(GLFW_KEY_ESCAPE)) return 0; /*exit the program*/
	glfwSwapBuffers(window);
	
	glClear(GL_COLOR_BUFFER_BIT); /*clear screen*/
	
	/*convert hex*/
	float r, g, b;
	r = hex >> 16;
	g = (hex & 0x00ff00) >> 8;
	b = (hex & 0x0000ff);
	
	/*convert float*/
	float c1 = (float)r / 255.0f; /*red*/
	float c2 = (float)g / 255.0f; /*green*/
	float c3 = (float)b / 255.0f; /*blue*/
	glClearColor(c1, c2, c3, 255); /*clear window specified color*/
	glfwPollEvents(); /*input*/
}

/*****************
/drawing functions
/****************/

/*draw a line*/
void dline(int x1, int y1, int x2, int y2, int hex)
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
	float q1 = (float)x1 / (float)sw;
  float p1 = (float)y1 / (float)sh;
	float q2 = (float)x2 / (float)sw;
	float p2 = (float)y2 / (float)sh;
	
	glBegin(GL_LINE_STRIP);
		glVertex2f(q1, p1);
		glVertex2f(q2, p2);
		glColor3f(r, g, b);
	glEnd();
}

/*draw a rectangle*/
void drect(int x, int y, int w, int h, int hex)
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
	float q = (float)x / (float)sw;
  float p = (float)y / (float)sh;
	float s = (float)w / (float)sw;
	float d = (float)h / (float)sw;
	
	glBegin(GL_POLYGON);
		glVertex2f(q, p);
		glVertex2f(q + s, p);
		glVertex2f(q + s, p - d);
		glVertex2f(q, p - d);
		glVertex2f(q + s, p - d);
		glColor3f(r, g, b);
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