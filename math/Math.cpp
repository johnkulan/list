#include "Math.h"
#include <iostream>

int Math::fuctorial(int N)
{
	if (N == 0)
		return 0;
	if (N == 1)
		return 1;
	return N * fuctorial(N - 1);
}
float Math::sin(float x, float eps)
{
	float result = 0.0F;
	int i = 0;
	x = x * pi / 180;
	float error = 1;
	while (error > eps)
	{
		error = power(x, (2 * i + 1)) / (fuctorial(2 * i + 1));
		result += (float)((power(-1, i)) * (error));
		i++;
	}

	return result;
}
float Math::sqrt(float x, float eps)
{
	float s = 1;
	float temp;

	do
	{
		float res = (s + x / s) / 2;
		temp = s - res;
		if (temp < 0) temp = -temp;
		s = res;
	} while (temp < eps);


	//for (;;)
	//{
	//	float res = (s + x / s) / 2;
	//	temp = s-res;
	//	if (temp < 0) temp = -temp;
	//	if (temp < eps)
	//		break;
	//	s = res;
	//}
	return s;

}
