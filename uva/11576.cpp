#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
#include<cstdio>
#include<string>
#include<cstring>
#include<cctype>
#include<queue>
#include<stack>
#include <functional>
#include<cmath>
#include<sstream>

using namespace std;

char scrol[105];
int table[105];


void fillTable(char *pattern, int len)
{
	table[0] = 0;
	table[1] = 0;
	int j;
	for(int i=2; i<=len; i++)
	{
		j = table[i-1];
		while(1)
		{
			if(pattern[j] == pattern[i-1])
			{
				table[i] = j + 1;
				break;
			}
			else if(j > 0)
			{
				j = table[j];
			}
			else
			{
				table[i] = 0;
				break;
			}
		}
	}
}

int kmp(char *pattern, int len)
{
	memset(table, 0, sizeof(table));
	fillTable(pattern, len);
	int i,j;
	for(i=0,j=0; i<len;)
	{
		if(pattern[j] == scrol[i])
		{
			i++;
			j++;
		}
		else if(j>0)
		{
			j = table[j];
		}
		else
		{
			i++;
		}
	}
	return j;
}

int main()
{
	int t;
	scanf("%d",&t);
	while (t--)
	{
		int k, l;
		scanf("%d%d",&k,&l);
		getchar();
		gets(scrol);
		int cost  = strlen(scrol);
		for(int i=1; i<l; i++)
		{
			char temp[101];
			gets(temp);
			int j = kmp(temp,k);
			cost = cost + (k-j);
			strcpy(scrol, temp);
		}
		printf("%d\n",cost);
	}
	return 0;
}