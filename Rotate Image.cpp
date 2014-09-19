#include <iostream>
#include <vector>

void swap(std::vector<std::vector<int>> &matrix, int row1, int col1, int row2, int col2)
{
	int tmp = matrix[row1][col1];
	matrix[row1][col1] = matrix[row2][col2];
	matrix[row2][col2] = tmp;
}

void swapByCross(std::vector<std::vector<int>> &matrix)
{
	int len = (int)matrix.size();
	for(int i = 0; i < len; ++i)
	{
		for(int j = i + 1; j < len; ++j)
		{
			swap(matrix, i, j, j ,i);
		}
	}
}

void swapByMiddle(std::vector<std::vector<int>> &matrix)
{
	int len = (int)matrix.size();
	for(int i = 0; i < len; ++i)
	{
		int left = 0;
		int right = len - 1;
		while(left < right)
		{
			swap(matrix, i, left, i, right);
			left++;
			right--;
		}
	}
}

void rotate(std::vector<std::vector<int>> &matrix)
{
	swapByCross(matrix);
	swapByMiddle(matrix);
}

int main()
{
	int n;
	std::cin>>n;
	int cnt = 0;
	std::vector<std::vector<int>> matrix;
	for(int i = 0; i < n; ++i)
	{
		std::vector<int> tmp;
		for(int j = 0; j < n; ++j)
		{
			tmp.push_back(cnt++);
		}
		matrix.push_back(tmp);
	}

	rotate(matrix);

	return 0;
}