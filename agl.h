#include <GLFW/glfw3.h>

/*creates window and clears it a certain color*/
int clear(int width, int height, int color[3])
{
	/*initialize glfw*/
	glfwInit();
		
	/*create a window with glfw*/
  GLFWwindow* window = glfwCreateWindow(width, height, " ", NULL, NULL);
	glfwMakeContextCurrent(window);
	

	while(!glfwWindowShouldClose(window))
	{
		/*clear screen*/
		glClearColor(color[1], color[2], color[3], 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    /*Swap front and back buffers*/
    glfwSwapBuffers(window);

    /*Poll for and process events*/
    glfwPollEvents();
	}
	
	glfwDestroyWindow(window); /*gets rid of window*/
	glfwTerminate(); /*ends glfw*/
	
	return 0;
}