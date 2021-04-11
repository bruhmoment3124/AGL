#include "../../agl.h"

/*collision*/
int collide(int x, int y, int w, int h)
{
	int collide = 0;
	if (x < -500 + 1000 &&
			x + w > -500 &&
			y < -400 + 100 &&
			y + h > -400) 
			{
			collide = 1;
	}
	
	return collide;
}

main()
{
	int x = 0, y = 0, dx = 0, dy = 0, standing = 0;
  win("Hello, World!", 500, 500);
	while(loop(0xdbdbdd)) /*set window color*/
	{
		drect(-500, -400, 500, 50, 0x1f1e23);
		drect(x, y, 50, 50, 0xe55656);
		end();
		
		dy-=1;
		if(input(65)) dx-=20;
		if(input(68)) dx+=20;
		if(input(32) && standing == 1) dy+=25;
		if(collide(x, y+dy, 50, 50)) 
		{
			standing = 1;
			dy = 0;
		} else
		{
			standing = 0;
		}
		
		x+=dx;
		y+=dy;
		dx*=.6;
		dy*=1;
	}
}