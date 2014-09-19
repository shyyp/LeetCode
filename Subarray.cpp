#include <iostream>

class Solution
{
public:
	int maxSubArray(int A[], int n)
	{
		int curSum = 0;
		int maxSum = 0;
		for(int i = 0; i < n; ++i)
		{
			curSum +=A[i];
			if(curSum < 0)
			{
				curSum = 0;
			}
			if(curSum > maxSum)
			{
				maxSum = curSum;
			}
		}

		if(maxSum == 0)
		{
			maxSum = A[0];
			for(int i = 1; i < n; ++i)
			{
				if(A[i] > maxSum)
				{
					maxSum = A[i];
				}
			}
		}

		return maxSum;
	}
};

int main()
{
	int A[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
	int n = 9;
	Solution sol;
	std::cout<<sol.maxSubArray(A, n);
	return 0;
}