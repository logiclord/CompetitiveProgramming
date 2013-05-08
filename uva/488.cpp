#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <set>
#include <vector>
#include<cstdio>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int ampl, freq;
		scanf("%d%d",&ampl, &freq);
		for(int i=0; i<freq; i++)
		{
			for(int j=1; j<=ampl; j++)
			{
				for(int k=0; k<j; k++)
				{
					printf("%d",j);
				}
				printf("\n");
			}
			for(int j=ampl-1; j>0; j--)
			{
				for(int k=0; k<j; k++)
				{
					printf("%d",j);
				}
				printf("\n");
			}
			if(i<freq-1)
				printf("\n");
		}
		if(t)
			printf("\n");
	}
	return 0;
}
