#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<functional>
#include<map>
#include<cmath>

#define INF 999999999
#define EPS 1e-9

using namespace std;

struct Point
{
	double x,y;
	Point(double x, double y)
	{
		this->x = x;
		this->y = y;
	}
};

double dotProduct(Point p2, Point p1,Point m)
{
	return ( (m.x - p2.x)*(p1.x-p2.x) + (m.y - p2.y)*(p1.y-p2.y) );
}

Point getIntercept(Point p1, Point p2, Point m)
{
	if(dotProduct(p1, p2, m) < EPS)
		return p1;
	else if(dotProduct(p2, p1, m) < EPS)
		return p2;
	else
	{
		Point ip(p2.x, p2.y);
		double scale = ( (m.x - p2.x)*(p1.x-p2.x) + (m.y - p2.y)*(p1.y-p2.y) )/ ( (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y) );

		ip.x += scale * (p1.x - p2.x);
		ip.y += scale * (p1.y - p2.y);
		return ip;
	}
}

int main()
{
	int x, y, p;
	while(scanf("%d%d%d", &x, &y, &p) != EOF)
	{
		Point pm(x,y);
		vector<Point> v;
		for(int i=0; i<=p; i++)
		{
			scanf("%d%d", &x, &y);
			v.push_back(Point(x,y));
		}

		Point answer = v.front();
		int dist =  INF;
		for(int i=0; i<p; i++)
		{
			Point ip = getIntercept(v[i], v[i+1], pm);
			double cur = hypot(ip.x - pm.x, ip.y - pm.y);
			if(cur < dist)
			{
				dist = cur;
				answer = ip;
			}
		}

		printf("%.4lf\n%.4lf\n", answer.x, answer. y);
	}
	return 0;
}


