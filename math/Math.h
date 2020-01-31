#pragma once
const float pi = 3.1415926535897932F;




class Math
{
public:
	static int fuctorial(int N);
	static float sin(float xF, float epsF);
	static float sqrt(float xF, float epsF);
	template <typename T>
	static T power(T var, int n)
	{
		T result = 1;

		for (int i = 0; i < n; i++)
		{
			result *= var;
		}
		return result;
	}

};


