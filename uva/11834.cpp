#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<functional>
#include<map>
#include<cmath>
#include<set>

#define INF 999999999
#define EPS 1e-9

using namespace std;

int main()
{
	int l,c,r1,r2;
	while(scanf("%d%d%d%d",&l,&c,&r1,&r2) && (l||c||r1||r2))
	{
		int x = l - r1 - r2;
		int y = c - r1 -r2;
		if(2*max(r1,r2)<=min(l,c) && (x*x + y*y >= (r1+r2)*(r1+r2)))
		{
			printf("S\n");
		}
		else
		{
			printf("N\n");
		}

	}
	return 0;
}
