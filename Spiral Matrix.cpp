#include <vector>

class Solution
{
public:
	std::vector<int> spiralOrder(std::vector<std::vector<int>> &matrix)
	{
		std::vector<int> res;
		int row = (int)matrix.size();
		if(row == 0)
		{
			return res;
		}
		int col = (int)matrix[0].size();

		int StartX = 0;
		int StartY = 0;
		while(row > StartX * 2 && col > StartY * 2)
		{
			spiralInCycle(matrix,res, StartX, StartY, row, col);
			StartX++;
			StartY++;
		}
		return res;
	}
private:
	void spiralInCycle(std::vector<std::vector<int>> &matrix, std::vector<int> &res, int StartX, int StartY, int row, int col)
	{
		int EndX = row - StartX - 1;
		int EndY = col - StartY - 1;
		LeftToRight(matrix,res, StartX, StartY, EndX, EndY);
		UpToDown(matrix,res, StartX, StartY, EndX, EndY);
		RightToLeft(matrix,res, StartX, StartY, EndX, EndY);
		DownToUp(matrix,res, StartX, StartY, EndX, EndY);
	}
	void LeftToRight(std::vector<std::vector<int>> &matrix,std::vector<int> &res, int StartX, int StartY, int EndX, int EndY)
	{
		for(int i = StartY; i <= EndY; ++i)
		{
			res.push_back(matrix[StartX][i]);
		}
	}
	void UpToDown(std::vector<std::vector<int>> &matrix,std::vector<int> &res, int StartX, int StartY, int EndX, int EndY)
	{
		if(StartX != EndX)
		{
			for(int i = StartX + 1; i <= EndX; ++i)
			{
				res.push_back(matrix[i][EndY]);
			}
		}
	}
	void RightToLeft(std::vector<std::vector<int>> &matrix, std::vector<int> &res, int StartX, int StartY, int EndX, int EndY)
	{
		if(StartX != EndX && EndY != StartY)
		{
			for(int i = EndY - 1; i >= StartY; --i)
			{
				res.push_back(matrix[EndX][i]);
			}
		}
	}
	void DownToUp(std::vector<std::vector<int>> &matrix, std::vector<int> &res, int StartX, int StartY, int EndX, int EndY)
	{
		if((EndX - StartX > 1) && StartY != EndY)
		{
			for(int i = EndX - 1; i >= StartX + 1; --i)
			{
				res.push_back(matrix[i][StartY]);
			}
		}
	}
};

int main()
{
	std::vector<std::vector<int>> matrix;
	std::vector<int> tmp;
	tmp.push_back(1);
	tmp.push_back(2);
	matrix.push_back(tmp);
	tmp.clear();
	tmp.push_back(3);
	tmp.push_back(4);
	matrix.push_back(tmp);
	tmp.clear();
	Solution sol;
	tmp = sol.spiralOrder(matrix);
	return 0;
}