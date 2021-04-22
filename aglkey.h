/*aglkey.h should be included AFTER agl.h*/
/*aglkey.h is used for input*/

/*takes ascii input until released*/
int agl_keyhold(int key)
{
	int state = glfwGetKey(window, key);
	return state;
}