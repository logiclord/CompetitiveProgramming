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
	int side[3];
	while(scanf("%d%d%d",&side[0], &side[1], &side[2])!=EOF)
	{
		sort(side, side+2);
		double s = ((double)(side[0] + side[1] + side[2]))/2.0;
		double tArea = sqrt(s*(s-side[0])*(s-side[1])*(s-side[2]));
		double iArea = Pi * (tArea * tArea * 1.0)/(s * s) ;
		double cR = (side[0]*side[1]*side[2])/(4*tArea);
		double cArea = Pi * cR * cR;
		printf("%.4lf %.4lf %.4lf\n",cArea-tArea, tArea-iArea, iArea);

	}
	return 0;
}
