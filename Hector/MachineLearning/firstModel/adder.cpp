#define NN_IMPLEMENTATION
#include "nn.h"

#define BITS 4

float td[] {
	0, 0
};
int main()
{	
	srand(time(0));
	size_t n = (1<<BITS);
	size_t rows = n*n;
	Mat ti = mat_alloc(rows, 2*BITS);
	Mat to = mat_alloc(rows, BITS+1);
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
	size_t arch[] = {2*BITS, 4*BITS,BITS ,BITS+1};
	NN nn = nn_alloc(arch, ARRAY_LEN(arch));
	NN g = nn_alloc(arch, ARRAY_LEN(arch));
	nn_rand(nn, 0, 1);
	NN_PRINT(nn);
	printf("c = %f\n",nn_cost(nn, ti, to));
	float rate = 1;

	for(size_t i = 0; i< 15000; ++i){
		nn_backprop(nn, g, ti, to);
		nn_learn(nn, g, rate);
		printf("%zu: c = %f\n",i ,nn_cost(nn, ti, to));
	}
	size_t fails = 0;
	for(size_t x = 0; x< n; ++x){
		for(size_t y = 0; y< n; ++y){
			size_t z = x+y;
			printf("%zu + %zu",x,y);
			for (size_t j = 0; j < BITS; ++j) {
				MAT_AT(NN_INPUT(nn), 0, j)        = (x>>j)&1;
				MAT_AT(NN_INPUT(nn), 0, j + BITS) = (y>>j)&1;
			}
			nn_forward(nn);
			if(MAT_AT(NN_OUTPUT(nn),0,BITS) > 0.5f){
				if(z<n)
				{
					printf("%zu + %zu = (OVERFLOW<>%zu)\n",x,y,z);
					fails+=1;
				}
				printf(" = OVERFLOWED\n");
			}else{
				size_t a = 0;

				for (size_t j = 0; j < BITS; ++j) {
					size_t bit = MAT_AT(NN_OUTPUT(nn),0,j)>0.5f;
					a|=bit<<j;
				}

				if(z!= a){
					printf("%zu + %zu = (%zu<>%zu)\n",x,y,z,a);
					fails+=1;
				}
			}
		}
	}
	if(fails == 0){ std::cout<<"ok\n";}
	else{std::cout<<fails<<std::endl;}
	return 0;
}
