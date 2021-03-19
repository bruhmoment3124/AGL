#include <GLFW/glfw3.h>

/*creates window and clears it a certain color*/
int win(int width, int height, float color[3])
{
	glfwInit(); /*initialize glfw*/
		
	/*create a window with glfw*/
  GLFWwindow* window = glfwCreateWindow(width, height, " ", NULL, NULL);
	glfwMakeContextCurrent(window);

	while(!glfwWindowShouldClose(window))
	{
		/*clear screen*/
		glClear(GL_COLOR_BUFFER_BIT);
		float r = color[0] / 255.0f; /*red*/
		float g = color[1] / 255.0f; /*green*/
		float b = color[2] / 255.0f; /*blue*/
		glClearColor(r, g, b, 255); /*clear window specified color*/
		
		glfwSwapBuffers(window);
    glfwPollEvents(); /*input*/
	}
	
	glfwDestroyWindow(window); /*gets rid of window*/
	glfwTerminate(); /*ends glfw*/
	
	return 0;
}