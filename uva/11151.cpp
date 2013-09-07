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


int dpHash[1001][1001];

int maxPallindrome(char *data, int i, int j)
{
	if(data==NULL || i>j)
		return 0;
	else if(i==j)
		return 1;
	else if(dpHash[i][j]!=-1)
		return dpHash[i][j];
	else
	{
		int len = 0;
		if(data[i]==data[j])
		{
			len = 2 + maxPallindrome(data, i+1, j-1);
		}
		else
		{
			len = max(len, max(maxPallindrome(data, i, j-1), maxPallindrome(data, i+1, j)));
		}
		return (dpHash[i][j]=len);
	}
}

int main()
{
	int t;
	scanf("%d",&t);
	char str[1001];
	gets(str);
	while(t--)
	{
		gets(str);
		int len = strlen(str);
		for(int i=0; i<=len; i++)
		{
			for(int j=0; j<=len; j++)
			{
				dpHash[i][j] = -1;
			}
		}
		cout<<maxPallindrome(str, 0, len-1)<<endl;
	}
	return 0;
}