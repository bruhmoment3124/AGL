#include <AGL/agl.h>

main()
{
	agl_window("person example", 500, 500);
	agl_begin(0);
		agl_line(0, 0, 50, -100, 0xFFFFFF); /* right leg */
		agl_line(0, 0, -50, -100, 0xFFFFFF); /* left leg */
		agl_line(0, 125, 50, 0, 0xFFFFFF); /* right arm*/
		agl_line(0, 125, -50, 0, 0xFFFFFF); /* left arm*/
		agl_line(0, 0, 0, 200, 0xFFFFFF); /* body */
		agl_circle(0, 200, 25, 25, 0xFFFFFF); /* head */
	agl_end();
}
