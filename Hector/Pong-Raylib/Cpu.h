#ifndef CPU_H
#define CPU_H
#include "Paddle.h"
class CpuPaddle: public Paddle
{
public:
	void Update(int ball_y){
		if(y+pHeight/2>ball_y)
			y-=speed;
		if(y+pHeight/2 <= ball_y)
			y+=speed;

		LimitMovement();
	}
};
#endif
