#include <vector>
#include <iostream>
#include <string>

class Solution
{
public:
	std::vector<std::vector<std::string>> solveNQueens(int n)
	{
		std::vector<std::vector<std::string>> res;
		int *RowToCol = new int[n];
		for(int i = 0; i < n; ++i)
		{
			RowToCol[i] = i;
		}
		permute(res, RowToCol, 0, n);
		return res;
	}
private:
	void swap(int A[], int i , int j)
	{
		int tmp = A[i];
		A[i] = A[j];
		A[j] = tmp;
	}
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
	void setMatrix(std::vector<std::vector<std::string>> &res, int A[], int n)
	{
		std::vector<std::string> tmp;
		for(int i = 0; i < n; ++i)
		{
			std::string str = "";
			for(int j = 0; j < n; ++j)
			{
				if(j == A[i])
				{
					str += 'Q';
				}
				else
				{
					str +='.';
				}
			}
			tmp.push_back(str);
		}
		res.push_back(tmp);
	}
	void permute(std::vector<std::vector<std::string>> &res, int A[], int index, int n)
	{
		if(index == n)
		{
			if(check(A, n))
			{
				setMatrix(res, A, n);
			}
		}

		for(int i = index; i < n; ++i)
		{
			int tmp = A[index];
			A[index] = A[i];
			A[i] = tmp;
			permute(res, A, index + 1, n);
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
	sol.solveNQueens(n);
	return 0;
}