/*aglkey.h should be included AFTER agl.h*/
/*aglkey.h is used for input*/

#ifdef __WIN32
	#include <windows.h>
#elif __LINUX__
	#include <unistd.h>
#endif

/*takes ascii input until released*/
int agl_keyhold(int key)
{
	int state = glfwGetKey(window, key);
	return state;
}
