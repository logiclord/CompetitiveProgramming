#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<string>
#include<sstream>
using namespace std;


void fillTable(int * table, string pattern)
{
	table[0] = 0;
	table[1] = 0;

	for(int index=2; index<=pattern.size(); index++)
	{
		int last = table[index-1];
		while(1)
		{
			if(pattern[last] == pattern[index-1])
			{
				table[index] = last + 1;
				break;
			}
			else if(last > 0)
			{
				last = table[last];
			}
			else
			{
				table[index] = 0;
				break;
			}
		}
	}
}

int kmp(string text, string pattern)
{
	int *table = new int[pattern.size() + 1];
	fillTable(table, pattern);

	int pIndex = 0, tIndex = 0;
	int firstMatch = -1;
	while(tIndex < text.size())
	{
		if(pattern[pIndex] == text[tIndex])
		{
			pIndex++;
			tIndex++;
			if(pIndex == pattern.size())
			{
				if(firstMatch == -1)
				{
					firstMatch = tIndex;
				}
				else
				{
					return tIndex-firstMatch;
				}
			}
		}
		else if(pIndex > 0)
		{
			pIndex = table[pIndex];
		}
		else
		{
			tIndex++;
		}
	}

	delete [] table;
	return tIndex-pIndex;
}

int main()
{
	int t;
	scanf("%d",&t);
	bool firstCase = true;
	while(t--)
	{
		if(firstCase == false)
			printf("\n");
		string text, pattern;
		cin>>pattern;
		//cin>>pattern;
		text.assign(pattern + pattern);
		cout<<kmp( text, pattern)<<endl;
		firstCase = false;
	}
	return 0;
}