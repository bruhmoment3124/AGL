#include <GLFW/glfw3.h>

GLFWwindow *window; /*create window object*/

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
  glClear(GL_COLOR_BUFFER_BIT); /*clear screen*/
	float c1 = (float)r / 255.0f; /*red*/
	float c2 = (float)g / 255.0f; /*green*/
	float c3 = (float)b / 255.0f; /*blue*/
	glClearColor(c1, c2, c3, 255); /*clear window specified color*/
	glfwSwapBuffers(window);
	glfwPollEvents(); /*input*/
	
	if(khold(GLFW_KEY_ESCAPE)) return 0;
	return 1;
}

/******************
/keyboard functions
/*****************/

/*keyboard press*/
int kpress(int key)
{
	
}

/*keyboard hold*/
int khold(int key)
{
	int state = glfwGetKey(window, key);
	if(state == GLFW_PRESS) return state;
}