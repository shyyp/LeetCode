#include <vector>
#include <iostream>
#include <string>

class Solution
{
public:
	int totalNQueens(int n)
	{
		int globalCnt = 0;
		int *RowToCol = new int[n];
		for(int i = 0; i < n; ++i)
		{
			RowToCol[i] = i;
		}
		permute(globalCnt, RowToCol, 0, n);
		return globalCnt;
	}
private:
	bool check(int A[], int n)
	{
		for(int i = 0; i < n; ++i)
		{
			for(int j = i + 1; j < n; ++j)
			{
				if(A[i] - A[j] == i - j || A[i] - A[j] == j - i)
				{
					return false;
				}
			}
		}
		return true;
	}
	void permute(int &globalCnt, int A[], int index, int n)
	{
		if(index == n)
		{
			if(check(A, n))
			{
				globalCnt++;
			}
		}

		for(int i = index; i < n; ++i)
		{
			int tmp = A[index];
			A[index] = A[i];
			A[i] = tmp;
			permute(globalCnt, A, index + 1, n);
			tmp = A[index];
			A[index] = A[i];
			A[i] = tmp;
		}
	}
};

int main()
{
	int n = 4;
	Solution sol;
	std::cout<<sol.totalNQueens(n);
	return 0;
}