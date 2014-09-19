#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <algorithm>

std::vector<std::string> anagrams(std::vector<std::string> &strs)
{
	std::vector<std::string> res;
	std::map<std::string, int> stringToIndex;
	std::map<std::string, int>::iterator iter;
	for(int i = 0; i < (int)strs.size(); ++i)
	{
		std::string tmp = strs[i];
		std::sort(tmp.begin(), tmp.end());
		iter = stringToIndex.find(tmp);
		if(stringToIndex.end() == iter)
		{
			stringToIndex[tmp] = i;
		}
		else
		{
			if(iter->second != -1)
			{
				res.push_back(strs[iter->second]);
				iter->second = -1;
				res.push_back(strs[i]);
			}
			else
			{
				res.push_back(strs[i]);
			}
		}
	}
	return res;
}

int main()
{
	return 0;
}