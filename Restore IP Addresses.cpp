#include <vector>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <iomanip>

class Solution
{
public:
	bool checkStr(std::string str)
	{
		if(str.size() == 1)
		{
			return "0" <= str && str <= "9";
		}
		else if(str.size() == 2)
		{
			return "10" <= str && str <= "99";
		}
		else if(str.size() == 3)
		{
			return "100" <= str && str <= "255";
		}
		return false;
	}
	std::vector<std::string> restoreIpAddresses(std::string s)
	{
		std::vector<std::string> ret;
		int sLen = (int)s.size();
		if(sLen < 4)
		{
			return ret;
		}
		int index = 0;
		std::vector<std::string> tmpV;
		partition(ret, s, tmpV, 0, 0);
		return ret;
	}
private:
	void partition(std::vector<std::string> &ret, std::string &s,
		std::vector<std::string> &tmpV, int index, int count)
	{
		if(count == 4)
		{
			if(index == (int)s.size())
			{
				std::string tmp = "";
				for(int i = 0; i < (int)tmpV.size(); ++i)
				{
					if(i == 0)
						tmp += tmpV[i];
					else
						tmp += ("." + tmpV[i]);
				}
				ret.push_back(tmp);
			}
			return;
		}
		for(int i = 1; i <= 3; ++i)
		{
			if(index + i <= (int)s.size())
			{
				std::string str = s.substr(index, i);
				if(checkStr(str))
				{
					tmpV.push_back(str);
					partition(ret, s, tmpV, index + i, count + 1);
					tmpV.pop_back();
				}
			}
		}
	}
};