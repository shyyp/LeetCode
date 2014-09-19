#include <iostream>

bool isMatch(const char *s, const char *p)
{
	if(*p == '\0')
	{
		return *s == 0;
	}

	if(*p == '*')
	{
		while(*p == '*')
		{
			++p;
		}

		while(*s != '\0')
		{
			if(isMatch(s, p))
			{
				return true;
			}
			++s;
		}

		return isMatch(s, p);
	}
	else
	{
		if((*s != '\0' && *p == '?') || *p == *s)
		{
			return isMatch(s + 1, p + 1);
		}
	}

	return false;
}

int main()
{
	return;
}