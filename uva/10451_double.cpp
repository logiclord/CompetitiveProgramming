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
	int n;
	double area;
	int ncase = 0;
	while(scanf("%d%lf", &n, &area)!=EOF && n>2)
	{
		double Pi = 2*acos(0.0);
		//double cR = sqrt((2*area)/(n * sin(2*Pi/n)));
		double Carea = (Pi*2*area)/(n * sin(2*Pi/n)) ; //Pi*cR*cR;
		//double iR = cR*cos(Pi/n);
		double Iarea = (Pi*2*area*cos(Pi/n)*cos(Pi/n))/(n * sin(2*Pi/n));//Pi*iR*iR;
		//cout.precision(5);
		//cout << fixed;
		//cout << "Case " << ++ncase << ": " << (float)(Carea-area) << " " << (float)(area-Iarea) << endl;
		printf("Case %d: %.5lf %.5lf\n", ++ncase, Carea-area, area-Iarea);
	}
	return 0;
}
