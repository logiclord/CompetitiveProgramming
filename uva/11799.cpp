#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<vector>
#include<map>
#include<cmath>
#include<algorithm>

using namespace std;

typedef long long ll; 
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 100000000

int main()
{
	int n,i=1;
	scanf("%d",&n);
	while(i<=n)
	{
		int t,p, mx = 0;
		scanf("%d",&t);
		while(t--)
		{
			scanf("%d",&p);
			mx = max(mx, p);
		}
		printf("Case %d: %d\n",i, mx);
		i++;
	}	
	return 0;
}
