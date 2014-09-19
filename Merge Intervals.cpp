#include <vector>
#include <iostream>
#include <algorithm>

struct Interval
{
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {};
};

bool cmp(Interval a, Interval b)
{
	return a.start < b.start;
}

class Solution
{
public:
	std::vector<Interval> merge(std::vector<Interval> &intervals)
	{
		int len = (int)intervals.size();
		if(len == 0 || len == 1)
		{
			return intervals;
		}
		std::vector<Interval> res;
		std::sort(intervals.begin(), intervals.end(), cmp);
		for(int i = 1; i < len; ++i)
		{
			if(intervals[i].start <= intervals[i - 1].end)
			{
				intervals[i].start = intervals[i - 1].start;
				intervals[i].end = intervals[i].end > intervals[i - 1].end ? intervals[i].end : intervals[i - 1].end;
			}
			else
			{
				res.push_back(intervals[i - 1]);
			}
		}
		res.push_back(intervals[len - 1]);
		return res;
	}
};

int main()
{
	Solution sol;
	std::vector<Interval> intervals;
	intervals.push_back(Interval(1, 4));
	intervals.push_back(Interval(2, 3));
	std::vector<Interval> res = sol.merge(intervals);
	return 0;
}

