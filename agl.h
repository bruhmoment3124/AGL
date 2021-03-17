#include <GLFW/glfw3.h>

/*creates window and clears it a certain color*/
int clear(int width, int height, float color[3])
{
	glfwInit(); /*initialize glfw*/
		
	/*create a window with glfw*/
  GLFWwindow* window = glfwCreateWindow(width, height, " ", NULL, NULL);
	glfwMakeContextCurrent(window);

	while(!glfwWindowShouldClose(window))
	{
		/*clear screen*/
    glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(color[1], color[2], color[3], 255); /*clear window specified color*/
		
    glfwSwapBuffers(window);
    glfwPollEvents(); /*input*/
	}
	
	glfwDestroyWindow(window); /*gets rid of window*/
	glfwTerminate(); /*ends glfw*/
	
	return 0;
}