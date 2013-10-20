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
	double Pi = 2*acos(0);
	int l,w,h, theta;
	while(scanf("%d%d%d%d",&l,&w,&h,&theta)!=EOF)
	{
		double cRad = atan((double)h/l);
		double tRad = (Pi*theta)/180.0;
		if(tRad < cRad)
		{
			double h2 = l*(double)tan(tRad);
			printf("%.3lf mL\n", 0.5*(h + h - h2)*l*w);
		}
		else
		{
			double h2 = (0.5*h*h)/tan(tRad);
			printf("%.3lf mL\n", h2*w);
		}
	}
	return 0;
}
