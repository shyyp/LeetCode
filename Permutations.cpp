#include <vector>
#include <iostream>
#include <algorithm>

void fullPermute(std::vector<std::vector<int>>& res, std::vector<int>& num, int index, int len)
{
	if(index == len)
	{
		res.push_back(num);
	}

	for(int i = index; i < len; ++i)
	{
		int tmp = num[index];
		num[index] = num[i];
		num[i] = tmp;
		fullPermute(res, num, index + 1, len);
		tmp = num[index];
		num[index] = num[i];
		num[i] = tmp;
	}
}

std::vector<std::vector<int>> permute(std::vector<int>& num)
{
	std::vector<std::vector<int>> res;
	int len = (int)num.size();
	fullPermute(res, num, 0, len);
	std::sort(res.begin(),res.end());
	return res;
}

int main()
{
	std::vector<int> num;
	std::vector<std::vector<int>> res;
	num.push_back(1);
	num.push_back(1);
	num.push_back(2);
	res = permute(num);
	return 0;
}