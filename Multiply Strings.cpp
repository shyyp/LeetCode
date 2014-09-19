#include <string>
#include <iostream>

std::string addnum(std::string num1, std::string num2)
{
	int lenOne = (int)num1.size();
	int lenTwo = (int)num2.size();
	int i = lenOne - 1;
	int j = lenTwo - 1;
	int flag = 0;
	std::string res = "";
	while(i >= 0 && j >=0)
	{
		int tmp = (num1[i] - '0') + (num2[j] - '0')+ flag;
		flag = tmp / 10;
		char c = tmp % 10 + '0';
		res = c + res;
		--i;
		--j;
	}
	std::string pre = "";
	if(i >= 0)
	{
		pre = num1.substr(0, i + 1);
	}
	if(j >= 0)
	{
		pre = num2.substr(0, j + 1);
	}
	if(flag)
	{
		int k = pre.size() - 1;
		while(k >= 0 && pre[k] == '9')
		{
			pre[k] = '0';
			--k;
		}
		if(k < 0)
		{
			pre = '1' + pre;
		}
		else
		{
			pre[k] += 1;
		}
	}
	res = pre + res;
	return res;
}

std::string multiplyOne(std::string num, int n)
{
	if(0 == n)
	{
		return "0";
	}

	int nLen = (int)num.size();
	int *res = new int[nLen + 1];
	
	for(int i = 0; i < nLen + 1; ++i)
	{
		res[i] = 0;
	}

	int flag = 0;
	for(int i = nLen - 1; i >= 0; --i)
	{
		int tmp = (num[i] - '0') * n + flag;
		res[i + 1] = tmp % 10;
		flag = tmp / 10;
	}
	if(flag > 0)
	{
		res[0] = flag;
	}

	std::string str = "";
	int i = 0;
	while(i < nLen + 1)
	{
		if(res[i] != 0)
		{
			break;
		}
		i++;
	}
	for(; i < nLen + 1; ++i)
	{
		str += ('0' + res[i]);
	}
	delete []res;
	return str;
}

std::string multiply(std::string num1, std::string num2)
{
	if(num1 == "0" || num2 == "0")
	{
		return "0";
	}

	int lenOne = (int)num1.size();
	int lenTwo = (int)num2.size();
	
	std::string res = "";
	for(int i = 0; i < lenTwo; ++i)
	{
		res += '0';
		std::string tmp = multiplyOne(num1, num2[i] - '0');
		res = addnum(tmp, res);
	}
	return res;
}

int main()
{
	std::string num1 = "6";
	std::string num2 = "501";

	std::cout<<multiply(num1, num2);

	return 0;
}