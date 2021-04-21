#include <stdio.h>
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
		if(dir == 0) agl_rectangle(x, y += size, size, size, hex); /*up*/
		if(dir == 1) agl_rectangle(x += size, y, size, size, hex); /*right*/
		if(dir == 2) agl_rectangle(x, y -= size, size, size, hex); /*down*/
		if(dir == 3) agl_rectangle(x -= size, y, size, size, hex); /*left*/
	}
}

main()
{
	int tiles; int size;
	printf("how many tiles do you want?\n");
	scanf("%d", &tiles);
	printf("what size would you like them to be?\n");
	scanf("%d", &size);
	
  agl_window("Hello, World!", 500, 500);
	agl_begin(0xFFFFFF);
		gen(tiles, size, 0x000000);
	agl_end();
}