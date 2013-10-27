#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<queue>
#include<map>
#include<set>
#include<functional>
#include<ctime>
#include<string>
#include<climits>
#include<cmath>
#include<stack>
#define EPS 1e-9

using namespace std;

double equation(double l, int r1, int r2)
{
	double w = (l*r2)/r1;
	return  l + sqrt(l*l + w*w)*0.5*acos(1.0 - (2*w*w)/(l*l + w*w)) - 200;
}

int main()
{
	int a, b;
	int tcase =1;
	char t;
	while(cin>>a>>t>>b)
	{
		double low = 0.0;
		double mid;
		double high = 200.0;
		while(fabs(high-low)>EPS)
		{
			mid = (low+high)/2;
			double eq = equation(mid, a, b);
			if(fabs(eq)<EPS)
				break;
			else if(eq > EPS)
				high = mid;
			else
				low= mid;
		}
		printf("Case %d: %lf %lf\n", tcase++,mid, b*mid/a);
	}
	return 0;
}