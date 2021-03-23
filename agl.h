#include <GLFW/glfw3.h>

GLFWwindow *window; /*create window object*/
static float width; /*screen width*/
static float height; /*screen height*/

/****************
/window functions
/***************/

/*creates window*/
void win(char *title, int width, int height)
{
	glfwInit(); /*initialize glfw*/
  window = glfwCreateWindow(width, height, title, NULL, NULL); /*create a window with glfw*/
	glfwMakeContextCurrent(window);
}

/*window loop*/
int loop(int r, int g, int b) /*background values*/
{
  if(input(GLFW_KEY_ESCAPE)) return 0; /*exit the program*/
	
	glClear(GL_COLOR_BUFFER_BIT); /*clear screen*/
	float c1 = (float)r / 255.0f; /*red*/
	float c2 = (float)g / 255.0f; /*green*/
	float c3 = (float)b / 255.0f; /*blue*/
	glClearColor(c1, c2, c3, 255); /*clear window specified color*/
	glfwPollEvents(); /*input*/
}

/*****************
/drawing functions
/****************/

/*end drawing*/
void dend()
{
	glfwSwapBuffers(window);
}

/*draw a line*/
void dline(int x1, int y1, int x2, int y2, float r, float g, float b)
{
	/*color values*/
	r /= 255.0f;
	g /= 255.0f;
	b /= 255.0f;
	
	/*convert opengl float values to standard X and Y*/
	float q1 = (float)x1 / 500.0f;
	float q2 = (float)x2 / 500.0f;
	float p1 = (float)y1 / 500.0f;
	float p2 = (float)y2 / 500.0f;
	
	glBegin(GL_LINE_STRIP);
		glVertex2f(q1, p1);
		glVertex2f(q2, p2);
		glColor3f(r, g, b);
	glEnd();
}

/******************
/keyboard functions
/*****************/

int input(int key)
{
	int state = glfwGetKey(window, key);
	if(state == GLFW_PRESS) return state;
}