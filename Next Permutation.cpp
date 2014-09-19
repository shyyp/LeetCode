#include <iostream>
#include <vector>

void swapNum(std::vector<int> &num, int a, int b)
{
	int tmp = num[a];
	num[a] = num[b];
	num[b] = tmp;
}

void reverseNum(std::vector<int> &num, int left, int right)
{
	while(left < right)
	{
		swapNum(num, left, right);
		left++;
		right--;
	}
}

void nextPermutation(std::vector<int> &num)
{
	int len = (int)num.size();
	int i = len - 2;
	for(; i >=0 && num [i] >= num[i + 1]; --i);
	if(i < 0)
	{
		reverseNum(num, 0 , len - 1);
		return;
	}
	int j = len - 1;
	for(; j > i && num[j] <= num[i]; --j);
	swapNum(num, i , j);
	reverseNum(num, i + 1, len - 1);
}





int main()
{
	int n = 3;
	std::vector<int> num;
	for(int i = 0; i < 3; ++i)
	{
		int tmp;
		std::cin>>tmp;
		num.push_back(tmp);
	}

	nextPermutation(num);
	return 0;
}