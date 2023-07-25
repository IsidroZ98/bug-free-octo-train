#define NN_IMPLEMENTATION
#include "nn.h"

#define BITS 2

float td[] {
	0, 0
};
int main()
{	
	size_t n = (1<<BITS);
	size_t rows = n*n;
	Mat ti = mat_alloc(rows, 2*BITS);
	Mat to = mat_alloc(rows, BITS+1);
#if 0
	for (size_t i = 0; i < ti.rows; ++i) {
        size_t x = i/n;
        size_t y = i%n;
        size_t z = x + y;
        for (size_t j = 0; j < BITS; ++j) {
            MAT_AT(ti, i, j)        = (x>>j)&1;
            MAT_AT(ti, i, j + BITS) = (y>>j)&1;
            MAT_AT(to, i, j)        = (z>>j)&1;
        }
        MAT_AT(to, i, BITS) = z >= n;
    }
#else
	for (size_t i = 0; i < ti.rows; ++i) {
        size_t x = i/n;
        size_t y = i%n;
        size_t z = x + y;
		size_t overflow = z >= n; 
        for (size_t j = 0; j < BITS; ++j) {
            MAT_AT(ti, i, j)        = (x>>j)&1;
            MAT_AT(ti, i, j + BITS) = (y>>j)&1;
			if(overflow)
			{
				MAT_AT(to,i,j) = 0;
			}else{
				MAT_AT(to, i, j)        = (z>>j)&1;
			}
		}
        MAT_AT(to, i, BITS) = overflow;
	}
#endif

	size_t arch[] = {2*BITS, BITS+1};
	NN nn = nn_alloc(arch, ARRAY_LEN(arch));
	NN g = nn_alloc(arch, ARRAY_LEN(arch));
	nn_rand(nn, 0, 1);
	NN_PRINT(g);
	NN_PRINT(nn);
	nn_cost(nn, ti, to);

	//nn_backprop(nn, g, ti, to);

	NN_PRINT(g);
	return 0;
}