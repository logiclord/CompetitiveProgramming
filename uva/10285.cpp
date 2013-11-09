#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

int fillState(int matrix[101][101], int dp[101][101], int n, int m, int i, int j)
{
	if(dp[i][j] != -1)
		return dp[i][j];

	int answer = 0;
	int x[] = {0,0, 1, -1};
	int y[] = {1,-1,0,0};

	for(int k=0; k<4;k++)
	{
		if(!(i+x[k] < 0 || i+x[k]>=n || j+y[k]<0 || j+y[k]>=m) && matrix[i+x[k]][j+y[k]] < matrix[i][j])
		{
			answer = max(answer, fillState(matrix, dp, n, m, i + x[k], j + y[k]));
		}
	}

	return dp[i][j] = answer+1;
}

int main()
{
	int n,m, t;
	char data[100];
	scanf("%d", &t);
	while(t--)
	{
		int matrix[101][101] = {0};
		int dp[101][101];
		scanf("%s%d%d", data, &n, &m);
		int answer = 0;
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<m; j++)
			{
				dp[i][j] = -1;
				scanf("%d", &matrix[i][j]);
			}
		}

		for(int i=0; i<n; i++)
		{
			for(int j=0; j<m; j++)
			{
				answer = max(answer, fillState(matrix, dp, n, m, i, j));
			}
		}
		printf("%s: %d\n",data, answer);
	}
	return 0;
}