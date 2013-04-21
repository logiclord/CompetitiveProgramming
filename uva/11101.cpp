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

using namespace std;

int hashy[2001][2001];
bool results[2001][2001];

int main()
{
	int p1,p2;
	while(scanf("%d",&p1)!=EOF && p1)
	{
		queue<pair<int,int> > qu;

		memset(hashy, -1, sizeof(hashy));
		memset(results, false, sizeof(results));

		int tmpx,tmpy;
		for(int i=0;i<p1;i++)
		{
			scanf("%d%d",&tmpx,&tmpy);
			qu.push(make_pair(tmpx,tmpy));
			hashy[tmpx][tmpy] = 0;
		}

		scanf("%d",&p2);
		for(int i=0;i<p2;i++)
		{
			scanf("%d%d",&tmpx,&tmpy);
			results[tmpx][tmpy] = true;
		}


		int movex[] = {0,1,0,-1};
		int movey[] = {1,0,-1,0};

		int ans = -1;
		// using bfs
		while(!qu.empty() && ans==-1)
		{
			pair<int,int> cur = qu.front();
			qu.pop();
			int tim = hashy[cur.first][cur.second];
			for(int i=0; i<4; i++)
			{
				int tx = movex[i] + cur.first;
				int ty = cur.second + movey[i];
				if(tx >=0 && ty>=0 && tx<=2000 && ty<=2000 && hashy[tx][ty]==-1)
				{
					hashy[tx][ty] = tim+1;
					if(results[tx][ty])
					{
						ans = tim+1;
						break;
					}
					qu.push(make_pair(tx,ty));
				}
			}
		}

		printf("%d\n",ans);

	}
	return 0;
}