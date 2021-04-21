#include "../../AGL.h"

main()
{
  agl_window("Hello, World!", 500, 500);
	agl_begin(0x000000);
		agl_rectangle(250, -100, 25, 50, 0xFF0000); /*up*/
		agl_rectangle(150, -200, 50, 25, 0xFF0000); /*left*/
		agl_rectangle(300, -200, 50, 25, 0xFF0000);	/*right*/
		agl_rectangle(250, -250, 25, 50, 0xFF0000); /*down*/
		
		agl_circle(-350, 350, 150, 150, 0x0000FF);
		agl_rectangle(-500, 200, 150, 150, 0x00FF00);
		agl_line(-500, -500, -200, -100, 0xFF0000);
		agl_line(-500, -100, -200, -500, 0xFF0000);
	agl_end();
}