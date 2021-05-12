#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <AGL/agl.h>

/*generate a random map*/
void gen(long long cycles, int size)
{
	srand(time(0)); /*random seed*/
	int x = 0, y = 0;
	
	long long i;
	for(i=0; i<=cycles; i++)
	{
		int dir = rand() % 4; /*random direction*/
		if(dir == 0) agl_rectangle(x, y += size, size, size, i); /*up*/
		if(dir == 1) agl_rectangle(x += size, y, size, size, i); /*right*/
		if(dir == 2) agl_rectangle(x, y -= size, size, size, i); /*down*/
		if(dir == 3) agl_rectangle(x -= size, y, size, size, i); /*left*/
	}
}

main()
{
	long long tiles, size;
	printf("how many tiles do you want?\n");
	scanf("%d", &tiles);
	printf("what size would you like them to be?\n");
	scanf("%d", &size);
	
  GLFWwindow *win = agl_window("procedural generation example", 500, 500);
	while(!glfwWindowShouldClose(win))
	{
		agl_begin(0xFFFFFF);
			gen(tiles, size);
		glfwSwapBuffers(win);
		glfwPollEvents();
	}
	glfwTerminate();
}