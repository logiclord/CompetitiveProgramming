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

using namespace std;

struct Point
{
	int x,y;
	Point(int x,int y)
	{
		this->x = x;
		this->y = y;
	}
	bool operator <(const Point &pt) const
	{
		if(pt.x == this->x)
			return this->y < pt.y;
		return this->x < pt.x;
	}
};

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n, x, y;
		vector<Point> v;
		scanf("%d",&n);
		for(int i=0; i<n; i++)
		{
			scanf("%d%d", &x, &y);
			v.push_back(Point(x,y));
		}
		double answer = 0.0;
		sort(v.begin(), v.end());

		int ylast = 0;
		for(int i=n-1; i>=0; i--)
		{
			if(v[i].y > ylast)
			{
				answer = answer + hypot((v[i].x - v[i+1].x), (v[i].y - v[i+1].y))*(v[i].y - ylast)/(v[i].y - v[i+1].y);
				ylast = v[i].y;
			}
		}
		printf("%.2lf\n",answer);
	}

	return 0;
}


