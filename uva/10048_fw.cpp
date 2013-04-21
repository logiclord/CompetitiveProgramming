#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
#include<cstdio>
#include<string>
#include<cstring>
#include<cctype>


using namespace std;


int main()
{
	int cas = 1;
	int c,s,q;
	while(scanf("%d%d%d",&c,&s,&q)!=EOF && (c||q||s))
	{
		int data[101][101];

		for(int i=1; i<=c; i++)
		{
			for(int j=1; j<=c; j++)
			{
				data[i][j] = 1000000;
			}
		}


		int x,y,dt;
		for(int i=1; i<=s; i++)
		{
			scanf("%d%d%d",&x,&y,&dt);
			data[x][y] = dt;
			data[y][x] = dt;
		}

		for(int k=1;k<=c;k++)
		{
			for(int i=1; i<=c; i++)
			{
				for(int j=1; j<=c; j++)
				{
					data[i][j] = min(data[i][j], max(data[i][k], data[k][j]));
				}
			}
		}

		if(cas!=1)
			printf("\n");

		printf("Case #%d\n",cas);

		for(int i=0; i<q;i++)
		{
			scanf("%d%d",&x,&y);
			if(data[x][y]==1000000)
				printf("no path\n");
			else
				printf("%d\n",data[x][y]);
		}
		cas++;
	}
	return 0;
}