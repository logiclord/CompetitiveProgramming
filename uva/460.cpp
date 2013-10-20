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

struct rec
{
	int xl, xr;
	int yl, yr;
};

struct Point
{
	int x,y;
	Point(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
};

int main()
{
	int t;
	cin>>t;
	bool blank = true;
	while(t--)
	{
		if(blank)
			printf("\n");
		blank =true;

		rec r1, r2;
		cin>>r1.xl>>r1.yl>>r1.xr>>r1.yr;
		cin>>r2.xl>>r2.yl>>r2.xr>>r2.yr;

		rec r3;
		r3.xl = max(r1.xl, r2.xl);
		r3.yl = max(r1.yl, r2.yl);
		r3.xr = min(r1.xr, r2.xr);
		r3.yr = min(r1.yr, r2.yr);

		if(r3.xl<r3.xr && r3.yl<r3.yr)
		{
			printf("%d %d %d %d\n",r3.xl, r3.yl, r3.xr, r3.yr);
		}
		else
		{
			printf("No Overlap\n");
		}
	}
	return 0;
}
