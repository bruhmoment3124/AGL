#include "../AGL.h"

main()
{
  win("Hello, World!", 500, 500);
	while(loop(0xFFFFFF)) /*set window color*/
	{
		end();
	}
}