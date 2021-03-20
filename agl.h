#include <GLFW/glfw3.h>

GLFWwindow *window; /*create window object*/

/*creates window*/
void win(char *title, int width, int height)
{
	glfwInit(); /*initialize glfw*/
	
	/*create a window with glfw*/
  window = glfwCreateWindow(width, height, title, NULL, NULL);
	glfwMakeContextCurrent(window);
}

/*window loop*/
int loop(float r, float g, float b) /*background values*/
{
	while(!glfwWindowShouldClose(window))
	{
		/*clear screen*/
		glClear(GL_COLOR_BUFFER_BIT);
		float c1 = r / 255.0f; 
		float c2 = g / 255.0f; 
		float c3 = b / 255.0f;
		glClearColor(c1, c2, c3, 255); /*clear window specified color*/
		glfwSwapBuffers(window);
    glfwPollEvents(); /*input*/
	}
	glfwDestroyWindow(window); /*gets rid of window*/
	glfwTerminate(); /*ends glfw*/
	
	return 0;
}