#include "../../AGL.h"

main()
{
	int c1 = 0xFF0000, c2 = 0xFF0000, c3 = 0xFF0000, c4 = 0xFF0000;
  win("Hello, World!", 500, 500);
	while(loop(0x000000)) /*set window color*/
	{
		drect(250, -100, 25, 50, c1); /*up*/
		drect(150, -200, 50, 25, c2); /*left*/
		drect(300, -200, 50, 25, c3);	/*right*/
		drect(250, -250, 25, 50, c4); /*down*/
		
		dcirc(-350, 350, 150, 150, 0x0000FF);
		drect(-500, 200, 150, 150, 0x00FF00);
		dline(-500, -500, -200, -100, 0xFF0000);
		dline(-500, -100, -200, -500, 0xFF0000);
		end();
		
		if(input(87)) c1 = 0x00FF00;
		if(input(65)) c2 = 0x00FF00;
		if(input(68)) c3 = 0x00FF00;
		if(input(83)) c4 = 0x00FF00;
	}
}