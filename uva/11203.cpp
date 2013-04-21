#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <set>
#include <vector>
#include<map>
#include<cstdio>
#include<stack>
#include<cstring>
#include<climits>
#include<cmath>
#include<queue>
#include<string>

using namespace std;

int main()
{
	char str[51];
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int valid = true;
		getchar();
		scanf("%[^\n]",str);
		int region = 0;
		int count[3] = {0};
		for(int i=0 ;valid && str[i]; i++)
		{
			if(str[i] == '?')
			{
				count[region]++;
			}
			else if((region == 0 && str[i]=='M') || (region == 1 && str[i]=='E'))
			{
				region++;
			}
			else
			{
				valid = false;
			}
		}

		if(valid && count[0]!=0 && count[1]!=0 && count[2]!=0 && count[0]+count[1]==count[2])
		{
			printf("theorem\n");
		}
		else
		{
			printf("no-theorem\n");
		}
	}

	//system("pause");
	return 0;
}


