#include "../../agl.h"
#include "../../aglkey.h"
#include "../../collision.h"

main()
{
	GLFWwindow *win = agl_window("Hello, World!", 500, 500);
	
	int x1 = 0, y1 = 0, x2 = 100, y2 = 0;
	int rect1[4] = {x1, y1, 50, 50};
	int rect2[4] = {x2, y2, 50, 50};
	
	while(!glfwWindowShouldClose(win))
	{
		agl_begin(0xFFFFFF);
			agl_rectangle(x1, y1, 50, 50, 0);
			agl_rectangle(x2, y2, 50, 50, 0);
		agl_takeinput();
		
		if(agl_keyhold(87)) y1+=5; /* up */
		if(agl_keyhold(83)) y1-=5; /* down */
		if(agl_keyhold(65)) x1-=5; /* left */
		if(agl_keyhold(68)) x1+=5; /* right */
	}
	glfwTerminate();
}