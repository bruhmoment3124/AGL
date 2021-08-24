
int agl_rectcollide(int sqr1[3], int sqr2[3])
{
	int collide = 0;
	if (sqr1[0] < sqr2[0] + sqr2[2] &&
			sqr1[0] + sqr1[2] > sqr2[0] &&
			sqr1[1] < sqr1[1] + sqr1[3] &&
			sqr1[1] + sqr1[3] > sqr2[1]) 
			{
			collide = 1;
	}
	return collide;
}