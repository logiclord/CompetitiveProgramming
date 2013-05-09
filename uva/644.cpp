#include<set>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<cstring>
#include<cctype>
#include<string>
#include<map>

using namespace std;

int main()
{
	string str;
	int setCount = 0;
	while(cin>>str)
	{
		map<string, bool> hash;
		setCount++;
		bool isValid = true;
		while(str[0]!='9')
		{
			hash[str] = true;
			cin>>str;
		}

		for(map<string, bool>::iterator it = hash.begin();isValid && it!=hash.end(); it++)
		{
			int size = it->first.length();
			for(int i=0; i<size-1; i++)
			{
				if(hash.find(it->first.substr(0, i+1))!=hash.end())
				{
					isValid = false;
					break;
				}
			}
		}

		if(isValid)
		{
			printf("Set %d is immediately decodable\n",setCount);
		}
		else
		{
			printf("Set %d is not immediately decodable\n",setCount);
		}
	}
	return 0;
}
