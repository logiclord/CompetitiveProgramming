#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;

int main()
{
	int t, count = 1;
	scanf("%d",&t);
	while(t--)
	{
		int d,v,u;
		double ans = 0;
		scanf("%d%d%d",&d,&v,&u);
		ans = sqrt(1-(((double) v)/u)*(((double) v)/u));
		ans = (((double) d)*(1-ans))/(ans*u);

		if(v<u && u>0 && v>0)
		{
			printf("Case %d: %.3f\n",count, ans );
		}
		else
		{
			printf("Case %d: can't determine\n", count);
		}
		count++;
	}
	return 0;
}
