#include <bits/stdc++.h>
#include <cstdio>
int data [][2]
{
	{0,0},
	{1,2},
	{2,4},
	{3,6},
	{4,8},
	{5,10},
	{6,12},
	{7,18},
};
#define data_size (sizeof(data)/sizeof(data[0]))
#define LOG(x) std::cout<<cost(x)<<std::endl 

float rand_float()
{
	return (float)rand()/(float)RAND_MAX;
}
float cost(float w, float b)
{
	float result = 0.0f;
	for(size_t i = 0; i < data_size; ++i)
	{
		float x = data[i][0];
		float y = x*w + b;
		float d = y - data[i][1];
		result+=d*d;
	}
	result /= data_size;
	return result;
}

int main()
{
	srand(90);
	float w = rand_float()*10.0f;
	float b = rand_float() * 5.0f;
	float rate = 1e-3;
	float eps = 1e-3;
	
	printf("%f\n",cost(w,b));
	for(size_t i = 0; i<1000 ;++i){
		float c =cost(w,b);  
		float dw = (cost(w+eps,b) - c)/eps;
		float db = (cost(w,b+eps) - c)/eps;
 
		w -= rate*dw;
		b -= rate*db;
		
		printf("cost = %f, w = %f, b = %f\n",cost(w,b), w, b);
	}
	printf("----------------\nw = %f, b= %f \n", w, b);

	return 0;
}
