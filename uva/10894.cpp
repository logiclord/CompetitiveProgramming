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


int data[101][101];

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF && n)
	{
		// pre-initialized 3D array
		char data[10][5][6] = {{"*****","*....","*****","....*","*****",}, {".***.","*...*","*****","*...*","*...*",},{"*...*","*...*","*...*",".*.*.","..*..",},{"*****","*....","***..","*....","*****",},{"*...*","*...*","*****","*...*","*...*",},{"*****","*...*","*****","*.*..","*..**",},{"*****","..*..","..*..","..*..","*****",},{"***..","*..*.","*...*","*..*.","***..",},{"*****","*...*","*...*","*...*","*****",},{"*...*",".*.*.","..*..","..*..","..*..", } };
		if(n<0)
		{
			n = -n;
			for(int k=0; k<10;k++)
			{
				if(k>0)
				{
					int maxi = (k==4)*2*n + n ;
					for(int m=0;m<maxi;m++)
					{
						for(int g=0;g<5*n;g++)
						{
							printf(".");
						}
						printf("\n");
					}
				}
				for(int j=0;j<5; j++)
				{
					for(int p=0; p<n; p++)
					{
						for(int i=0; i<5; i++)
						{
							for(int z=0; z<n; z++)
							{
								printf("%c",data[k][j][i]);
							}
						}
						printf("\n");
					}
				}
			}
		}
		else
		{
			for(int j=0; j<5;j++)
			{
				for(int p=0; p<n; p++)
				{
					for(int k=0;k<10; k++)
					{
						if(k>0)
						{
							int maxi = (k==4)*2*n + n ;
							for(int m=0;m<maxi;m++)
							{
								printf(".");
							}
						}
						for(int i=0; i<5; i++)
						{
							for(int z=0; z<n; z++)
							{
								printf("%c",data[k][j][i]);
							}
						}
					}
					printf("\n");
				}
			}
		}
		printf("\n\n");
	}
	return 0;
}