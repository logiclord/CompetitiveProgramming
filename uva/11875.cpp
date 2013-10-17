#include<iostream>
#include<cmath>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int t, count = 1;
	scanf("%d",&t);
	while(t--)
	{
		vector<int> v;
		int temp;
		int n;
		scanf("%d", &n);
		for(int i=0; i<n; i++)
		{
			scanf("%d",&temp);
			v.push_back(temp);
		}

		sort(v.begin(), v.end());

		printf("Case %d: %d\n",count, v[v.size()/2] );

		count++;
	}
	return 0;
}
