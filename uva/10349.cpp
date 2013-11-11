#include<iostream>
#include<algorithm>
#include<cstdio>
#include<map>
#include<vector>
#include<list>
#include<stack>
#include<string>
#include<sstream>
using namespace std;

int t, n, m;
char data[50][50];
pair<int,int> owner[50][50];

int AlternatePath(int visited[50][50], int i, int j)
{
	if(!visited[i][j])
	{
		visited[i][j] = 1;
		int x[] = {0,0,1,-1};
		int y[] = {1,-1,0,0};
		for(int k=0; k<4; k++)
		{
			if(i+x[k]>=0 && i+x[k]<n && j+y[k]>=0 && j+y[k]<m && data[i+x[k]][j+y[k]] == '*' && (owner[i+x[k]][j+y[k]] == make_pair(-1,-1) || AlternatePath(visited, owner[i+x[k]][j+y[k]].first, owner[i+x[k]][j+y[k]].second)))
			{
				owner[i+x[k]][j+y[k]]  = make_pair(i,j);
				return 1;
			}
		}
	}
	return 0;
}

int main()
{

	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<m; j++)
			{
				cin>>data[i][j];
				owner[i][j] = make_pair(-1,-1);
			}
		}


		int maxi = 0;
		int vertex = 0;
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<m; j++)
			{
				if(data[i][j] == '*')
				{
					vertex++;
					if( (i+j)%2==0)
					{
						int visited[50][50] = {0};
						maxi += AlternatePath(visited, i, j);
					}
				}
			}
		}
		cout<<vertex-maxi<<endl;

	}
	return 0;
}