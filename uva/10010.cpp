#include<iostream>
#include<cstdio>
#include<ctype.h>

using namespace std;

void lower(char * str)
{
	for(int i=0; str[i]; i++)
	{
		str[i] = tolower(str[i]);
	}
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n,m,k;
		char data[51][51];
		scanf("%d%d", &n, &m);
		for(int i=0; i<n; i++)
		{		
			getchar();
			scanf("%[^\n]",data[i]);
			lower(data[i]);
		}
		scanf("%d",&k);
		char pattern[51];
		int directionX[] = {1, 1, -1, -1, 0, 1, -1,  0};
		int directionY[] = {1,-1,  1, -1, 1, 0,  0, -1};

		for(int i=0 ; i< k; i++)
		{
			getchar();
			scanf("%[^\n]",pattern);
			lower(pattern);
			bool found = false;
			for(int i=0; i<n && !found; i++)
			{	
				for(int j=0; j<m && !found; j++)
				{	
					if(data[i][j] == pattern[0])
					{
						for(int k = 0; k<8 && !found; k++)
						{
							bool valid = true;
							for(int p=1; pattern[p]; p++)
							{
								int x = i + p*directionX[k] ;
								int y = j + p*directionY[k];
								if( x< 0 || x >= n || y < 0 || y >=m || pattern[p] != data[x][y])
								{
									valid = false;
									break;
								}
							}
							found = valid;
						}
					}
					if(found)
					{
						printf("%d %d\n",i+1,j+1);
					}
				}
			}
		}
		if(t)
		{
			printf("\n");
		}
	}
	return 0;
}