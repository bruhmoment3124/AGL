/* code adapted from this article 
   http://warp.povusers.org/Mandelbrot/
*/

#include <stdbool.h>
#include "../../AGL.h"

main()
{
	agl_window("Hello, World!", 500, 500);
	
	double MinRe = -2.0;
	double MaxRe = 1.0;
	double MinIm = -1.2;
	double MaxIm = MinIm+(MaxRe-MinRe)*500/500;
	double Re_factor = (MaxRe-MinRe)/(500-1);
	double Im_factor = (MaxIm-MinIm)/(500-1);
	unsigned MaxIterations = 30;
	
	unsigned x, y, n;
	
	agl_begin(0xFFFFFF); /*set window color*/
		for(y=0; y<1000; ++y)
		{
			double c_im = MaxIm - y*Im_factor;
			for(x=0; x<1000; ++x)
			{
				double c_re = MinRe + x*Re_factor;
					
				double Z_re = c_re, Z_im = c_im;
				bool isInside = true;
				for(n=0; n<MaxIterations; ++n)
				{
					double Z_re2 = Z_re*Z_re, Z_im2 = Z_im*Z_im;
					if(Z_re2 + Z_im2 > 4)
					{
						isInside = false;
						break;
					}
					Z_im = 2*Z_re*Z_im + c_im;
					Z_re = Z_re2 - Z_im2 + c_re;
				}
				if(isInside) agl_rectangle(x, y, 1, 1, 0);
			}
		}
	agl_end();
}