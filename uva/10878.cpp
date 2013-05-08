#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <set>
#include <vector>
#include<cstdio>
#include<cstring>

using namespace std;

int main()
{
	char data[100];
	scanf("%[^\n]",data);
	getchar();
	char cur = 0;
	while(scanf("%[^\n]",data) !=EOF && data[0]!='_')
	{
		getchar();
		cur = 0;
		for(int i=1; data[i]!='|'; i++)
		{
			if(data[i]=='.')
				i++;
			cur = (cur<<1) | (data[i]=='o');
		}
		printf("%c",(char)cur);
	}
	return 0;
}
