#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
#include<cstdio>
#include<string>
#include<cstring>
#include<cctype>
#include<queue>
#include<stack>
#include <functional>
#include<cmath>

#define MAXD 4

using namespace std;

struct state
{
	int dir;
	int x;
	int y;
	int color;

	bool operator < (const state& f) const
	{
		if(dir < f.dir) return true;
		if(x < f.x) return true;
		if(y < f.y) return true;
		if(color < f.color) return true;
		return false;
	}
	state(int d, int x, int y, int color)
	{
		this->dir = d;
		this->x = x;
		this->y = y;
		this->color = color;
	}
};

int n,m;
char data[50][50];

bool isValid(int x,int y)
{
	bool ret = (x>=0 && x<n && y>=0 && y< m && data[x][y]!='#');
	//cerr<<x<<" "<<y<<" "<<ret<<endl;
	return ret;
}


int visited[10][30][30][10];

void setVisited(state s, int val)
{
	visited[s.dir][s.x][s.y][s.color] = val;
}

int getVisited(state s)
{
	return	visited[s.dir][s.x][s.y][s.color];
}

int main()
{
	int cases = 1;
	while(scanf("%d%d",&n,&m) && (n|m))
	{
		int answer = -1;
		int sx,sy;
		int tx,ty;
		memset(visited, -1, sizeof(visited));

		for(int i=0; i<n; i++)
		{
			getchar();
			for(int j=0; j<m; j++)
			{
				scanf("%c",&data[i][j]);
				if(data[i][j]=='S')
				{
					sx = i;
					sy = j;
				}
				else if(data[i][j]=='T')
				{
					tx = i;
					ty = j;
				}
			}
		}

		int movex[] = {-1,0,1,0};
		int movey[] = {0,1,0,-1};

		queue<state> qu;
		state start(0, sx, sy, 0);
		qu.push(start);
		setVisited(start,0);

		while(!qu.empty())
		{
			state cur = qu.front();
			int tim = getVisited(cur);
			qu.pop();

			if(isValid(cur.x + movex[cur.dir], cur.y + movey[cur.dir]))
			{
			//	cout<<"in1\n";
				state nextm(cur.dir,cur.x + movex[cur.dir],cur.y + movey[cur.dir],(cur.color+1)%5);
				if(getVisited(nextm) == -1)
				{
					setVisited(nextm, tim+1);
					qu.push(nextm);
				}

				if(nextm.x == tx && nextm.y == ty && nextm.color == 0)
				{
					answer = tim+1;
					break;
				}
			}
			state nextl((MAXD + cur.dir - 1 )%MAXD, cur.x, cur.y, cur.color);
			if(getVisited(nextl) == -1)
			{
				//cout<<"in2\n";
				setVisited(nextl, tim+1);
				qu.push(nextl);

			}
			state nextr((cur.dir + 1 )%MAXD, cur.x, cur.y, cur.color);
			if(getVisited(nextr) == -1)
			{
			//	cout<<"in3\n";
				setVisited(nextr, tim+1);
				qu.push(nextr);
			}
		}

		if(cases!=1)
			printf("\n");

		printf("Case #%d\n",cases);
		if(answer==-1)
		{
			printf("destination not reachable\n");
		}
		else
		{
			printf("minimum time = %d sec\n",answer);
		}
		cases++;
	}
	return 0;
}
