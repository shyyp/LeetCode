#include <iostream>

class Solution
{
public:
	bool canJump(int A[], int n)
	{
		if(0 == n)
		{
			return false;
		}
		int index = A[0];
		for(int i = 0; i < n - 1; ++i)
		{	
			if(i <= A[0])
			{
				int tmp = i + A[i];
				if(tmp > index)
				{
					index = tmp;
				}
			}
		}
		return (index >= n-1 ? true : false);
	}
};

int main()
{
	int n;
	std::cin>>n;
	int *A = new int[n];
	for(int i = 0; i < n; ++i)
	{
		std::cin>>A[i];
	}
	Solution sol;
	bool flag = sol.canJump(A, n);
	std::cout<<(flag ? "true" : "false");
	return 0;
}