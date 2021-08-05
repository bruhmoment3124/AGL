#include <AGL/agl.h>
#include <AGL/aglkey.h>

main()
{
  GLFWwindow *win = agl_window("shapes example", 500, 500);
	
	int c1 = 0xFF0000, c2 = 0xFF0000, c3 = 0xFF0000, c4 = 0xFF0000;
	while(!glfwWindowShouldClose(win))
	{
		agl_begin(0x000000);
			agl_rectangle(250, -100, 25, 50, c1); /*up*/
			agl_rectangle(150, -200, 50, 25, c2); /*left*/
			agl_rectangle(300, -200, 50, 25, c3);	/*right*/
			agl_rectangle(250, -250, 25, 50, c4); /*down*/
		
			agl_circle(-350, 350, 150, 150, 0x0000FF);
			agl_rectangle(-500, 200, 150, 150, 0x00FF00);
			agl_line(-500, -500, -200, -100, 0xFF0000);
			agl_line(-500, -100, -200, -500, 0xFF0000);
		agl_takeinput();
		
		if(agl_keyhold(87)) c1 = 0x00FF00;
		if(agl_keyhold(65)) c2 = 0x00FF00;
		if(agl_keyhold(68)) c3 = 0x00FF00;
		if(agl_keyhold(83)) c4 = 0x00FF00;
	}
	glfwTerminate();
}