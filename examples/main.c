#include "../AGL.h"

void main()
{
	int x = 0; int y = 0;
  win("Hello, World! (press escape to quit)", 1920, 1080);
	while(loop(0xdcac6c)) /*set window color*/
	{
		drect(x, y, 25, 25, 0xe55656);
		end(); /*end drawing*/
		
		if(input(87)) y++;
		if(input(65)) x--;
		if(input(83)) y--;
		if(input(68)) x++;
	}
}