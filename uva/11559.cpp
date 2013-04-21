#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<vector>
#include<map>
#include<cmath>

using namespace std;

typedef long long ll; 
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000



int main()
{
	int n,b,h,w;
	while(scanf("%d%d%d%d",&n,&b,&h,&w) != EOF)
	{
		ll minimum = INF;
		//cout<<b<<endl;
		for(int i=0; i<h; i++)
		{
			int tmp,c;
			scanf("%d",&c);
			tmp = c*n;
			for(int j=0;j<w; j++)
			{
				int p;
				scanf("%d",&p);
				if(p >= n && tmp <= b && minimum > tmp)
				{
					minimum = tmp;
				}
			}
		}
		if(minimum == INF)
		{
			printf("stay home\n");
		}
		else
		{
			printf("%lld\n",minimum);
		}
	}	
	return 0;
}
