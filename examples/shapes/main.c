#include "../../AGL.h"

main()
{
  win("Hello, World!", 500, 500);
	begin(0x000000);
		drect(250, -100, 25, 50, 0xFF0000); /*up*/
		drect(150, -200, 50, 25, 0xFF0000); /*left*/
		drect(300, -200, 50, 25, 0xFF0000);	/*right*/
		drect(250, -250, 25, 50, 0xFF0000); /*down*/
		
		dcirc(-350, 350, 150, 150, 0x0000FF);
		drect(-500, 200, 150, 150, 0x00FF00);
		dline(-500, -500, -200, -100, 0xFF0000);
		dline(-500, -100, -200, -500, 0xFF0000);
	end();
}