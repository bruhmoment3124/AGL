#include <stdlib.h>
#include <time.h>
#include "../../AGL.h"

/*generate a random map*/
void gen(int cycles, int size, int hex)
{
	srand(time(0)); /*random seed*/
	int x = 0, y = 0;
	
	int i;
	for(i=0; i<=cycles; i++)
	{
		int dir = rand() % 4; /*random direction*/
		if(dir == 0) drect(x, y += size, size, size, hex); /*up*/
		if(dir == 1) drect(x += size, y, size, size, hex); /*right*/
		if(dir == 2) drect(x, y -= size, size, size, hex); /*down*/
		if(dir == 3) drect(x -= size, y, size, size, hex); /*left*/
	}
}

main()
{
  win("Hello, World!", 500, 500);
	while(loop(0xFFFFFF)) /*set window color*/
	{
		gen(500, 16, 0x000000);
		end();
	}
}