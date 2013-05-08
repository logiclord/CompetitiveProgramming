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
	int t;
	scanf("%d",&t);
	for(int i=1; i<=t; i++)
	{
		char input[51];
		int  rows[51];
		int len = 0;
		scanf("%s",input);

		int maxi = 0;
		int mini = 0;
		len = 1;
		rows[0] = 0;

		while(input[len])
		{
			if(input[len-1] == 'F' || input[len-1] == 'C')
			{
				rows[len] = rows[len-1];
			}
			else
			{
				rows[len] = rows[len-1] + 1;
			}
			if(input[len] == 'F')
				rows[len]--;

			maxi = max(maxi, rows[len]);
			mini = min(mini, rows[len]);
			len++;
		}


		printf("Case #%d:\n",i);
		for(int j=maxi; j>=mini; j--)
		{
			printf("| ",j);
			int lastfound = -1;
			for(int k=0; k<len;k++)
			{
				if(rows[k]==j)
				{
					for(int p = lastfound; p < k-1; p++)
					{
						printf(" ");
					}
					lastfound = k;
					switch(input[k])
					{
					case 'R': printf("/"); break;
					case 'C': printf("_"); break;
					case 'F': printf("\\"); break;
					}
				}
			}
			printf("\n");
		}
		printf("+");
		for(int j=-1; j<=len; j++)
		{
			printf("-");
		}
		printf("\n\n");
	}
	return 0;
}
