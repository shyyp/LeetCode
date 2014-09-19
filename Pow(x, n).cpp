#include <iostream>

class Solution
{
public:
	double pow(double x, int n)
	{
		if(0 == n)
		{
			return 1;
		}
		bool isNegative = false;
		if(n <= 0)
		{
			isNegative = true;
		}
		n = abs(n);
		long double res = pow(x, n / 2);
		res = n & 0x1 ? res*res*x : res*res;
		return isNegative ? 1/res : res;
	}
};

int main()
{
	Solution s;
	std::cout<<s.pow(34.00515, -3);
	return 0;
}