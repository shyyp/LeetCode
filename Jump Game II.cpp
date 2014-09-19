#include <iostream>
#include <limits>

int jump(int A[], int n)
{
	if(0 == n)
	{
		return INT_MAX;
	}
	int *dp = new int[n];
	dp[0] = 0;
	for(int i = 1; i < n; ++i)
	{
		dp[i] = INT_MAX;
	}
	for(int i = 1; i < n; ++i)
	{
		for(int j = 0; j < i; ++j)
		{
			if(j + A[j] >= i)
			{
				if(dp[j] + 1 < dp[i])
				{
					dp[i] = dp[j] + 1;
					break;
				}
			}
		}
	}
	return dp[n -1];
}