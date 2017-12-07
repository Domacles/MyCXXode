float sqrt_magic(float number) 
{
    const float f = 1.5F;
	float x = number * 0.5F;


    long  i  = * ( long  * ) &number;   /*将float当作long强行取出*/
          i  = 0x5f3759df - ( i >> 1 ); /*获得一个比较理想的猜测值*/
    float y  = * ( float * ) &i;        /*转换回float*/

	for(int i=0; i<3; ++i)
		y  = y * ( f - ( x * y * y ) );/*牛顿法求1/√number*/
    
	return number * y;  /* number *1/√number =√number */
};

void swap(int a, int b)
{    /* ^ 可以换成 + - */
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}


int count(unsigned int a)
{
	int t[5] = {0x55555555,
		        0x33333333,
				0x0F0F0F0F,
				0x00FF00FF,
				0x0000FFFF};

	for(int i=0; i<5; ++i )
		a = (a & t[i]) + ((a & ( t[i]<<(1<<i) ))>>(1<<i));

	return a;
}