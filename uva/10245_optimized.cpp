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
#include<vector>
#include<cassert>
#define EPS 1e-9
#define INF 2000000000;
using namespace std;

struct Point
{
	double x,y;
	bool operator==(const Point &p) const
	{
		return fabs(p.x - this->x)<EPS && fabs(p.y - this->y)<EPS;
	}
};

bool compX(Point p1, Point p2)
{
	return p1.x < p2.x || (fabs(p1.x - p2.x)<EPS && p1.y < p2.y);
}

bool compY(Point p1, Point p2)
{
	return p1.y < p2.y || (fabs(p1.y - p2.y)<EPS && p1.x < p2.x);
}

double  dist(Point a, Point b)
{
	return  (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}

double  closestPair(vector<Point> &xaxis, int p, int q, vector<Point> &yaxis)
{
	double  answer = INF;
	int divide = q-p+1;
	
	if(divide>0 && divide<=3)
	{
		for(int i=0; i<divide; i++)
		{
			for(int j=i+1; j<divide; j++)
			{
				answer = min(answer, dist(xaxis[p + i], xaxis[p + j]));
			}
		}
	}
	else if(divide > 3)
	{
		divide = (p+q)/2;
		vector<Point> yleft, yright, yleftm, yrightm;

		for(vector<Point>::iterator it = yaxis.begin(); it!=yaxis.end(); it++)
		{
			if(compX(*it, xaxis[divide]) || xaxis[divide] == *it)
				yleft.push_back(*it);
			else
				yright.push_back(*it);
		}

		//assert(yleft.size() == divide-p+1);
		//assert(yright.size() == q-divide);

		double  d1 = closestPair(xaxis, p, divide, yleft);
		double  d2 = closestPair(xaxis, divide+1, q, yright);
		double  d = min(d1, d2);
		double  xmin = xaxis[divide].x - d;
		double  xmax = xmin + d + d;

		for(vector<Point>::iterator it = yleft.begin(); it!=yleft.end(); it++)
		{
			if(it->x > xmin && it->x < xmax)
				yleftm.push_back(*it);
		}

		for(vector<Point>::iterator it = yright.begin(); it!=yright.end(); it++)
		{
			if(it->x > xmin && it->x < xmax)
				yrightm.push_back(*it);
		}

		int n = yleftm.size(), m = yrightm.size(), j = 0, r = 0;
		for(int i=0; i<n && j<m; i++)
		{
			while(j<m && yrightm[j].y + d < yleftm[i].y)
				j++;
			int p = j;
			while(j<m && yrightm[j].y <= yleftm[i].y + d)
			{
				d = min(d, dist(yleftm[i], yrightm[j]));
				j++;
			}
			j = p;
		}

		answer = d;
	}
	return answer;
}

int main()
{
	int n;
	while(scanf("%d", &n)!=EOF && n>0)
	{
		vector<Point> xaxis(n);
		vector<Point> yaxis;

		for(int i=0; i<n; i++)
		{
			scanf("%lf%lf", &xaxis[i].x, &xaxis[i].y); 
		}

		yaxis.assign(xaxis.begin(), xaxis.end());
		sort(xaxis.begin(), xaxis.end(), compX);
		sort(yaxis.begin(), yaxis.end(), compY);
		double answer  = INF;

		for(int i=0; i<=n-2; i++)
		{
			if(xaxis[i] == xaxis[i+1])
			{
				answer = 0.0;
				break;
			}
		}

		if(answer > 1 )
			answer = sqrt(closestPair(xaxis,0, n-1, yaxis));

		if(answer < 10000)
		{
			printf("%.4lf\n", answer);
		}
		else
		{
			printf("INFINITY\n");
		}
	}

	return 0;
}