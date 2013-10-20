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

struct Point
{
	int x,y;
	Point(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	bool operator < (const Point & pt) const 
	{
		if(this->x == pt.x)
			return this->y < pt.y;
		return this->x < pt.x;
	}
};

int ccw(vector<Point> & pt, int i, int j, int k)
{
	return (pt[i].x - pt[j].x)*(pt[k].y - pt[j].y) - (pt[k].x - pt[j].x)*(pt[i].y - pt[j].y) ; 
}

int main()
{
	int t, n;
	scanf("%d", &t);
	int ncase  = 1;
	while(t--)
	{
		scanf("%d", &n);
		double x,y;
		set<Point> pointss;
		for(int i=0; i<n ;i++)
		{
			scanf("%lf%lf", &x, &y);
			pointss.insert(Point(x*100, y*100));
		}
		vector<Point> points(pointss.begin(), pointss.end());
		int ucount = pointss.size();
		int data[101][101] = {0};

		for(int i=0; i<ucount; i++)
		{
			for(int j=i+1; j<ucount; j++)
			{
				for(int k=j+1; k<ucount; k++)
				{
					if(ccw(points, i,j,k) == 0)
					{
						//int maxi = max(data[i][j], max(data[j][k], data[k][i]));
						//data[i][j]=data[j][k]=data[k][i] = maxi+1;
						data[i][j]++;
						data[j][k]++;
						++data[k][i] ;
					}
				}
			}
		}

		int col = 0;
		for(int i=0; i<ucount; i++)
		{
			for(int j=0; j<ucount; j++)
			{
				col = max(col, data[i][j]);
			}
		}

		if(ucount == 1)
		{
			printf("Data set #%d contains a single gnu.\n", ncase);
		}
		else
		{
			printf("Data set #%d contains %d gnus, out of which a maximum of %d are aligned.\n", ncase, ucount, col+2);
		}
		ncase++;

	}
	return 0;
}





