#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

int data[62505], prince[62505], princess[62505];
int p[62505], b[62505];

// Longest Common Subsequence using Longest Increasing Subsequence
int GetLIS(int a[], int len)
{
	memset(p, len*sizeof(int), 0);
	int bLast = 0;
	
	b[bLast++] = 0;
	p[0] = -1;

	for(int i=1; i<len; i++)
	{
		if(data[a[i]] > data[a[b[bLast-1]]])
		{
			p[i] = b[bLast-1];
			b[bLast++] = i;
			continue;
		}

		int beg = 0, end = bLast-1, mid;
		while(beg<end)
		{
			mid = (beg+end)/2;
			if(data[a[b[mid]]] < data[a[i]])
				beg = mid+1;
			else
				end = mid;
		}

		if(data[a[b[beg]]] > data[a[i]]) 
		{
			if(beg>0)
				p[i] = b[beg-1];
			b[beg] = i;
		}
	}
	return bLast;
}

int main()
{
	int t, n,p,q;
	int count = 1;
	scanf("%d", &t);
	while(t--)
	{
		bool useOne = false;
		int dummy;
		scanf("%d%d%d", &n, &p, &q);
		n = n*n;
		for(int i=0; i<=n; i++)
		{
			data[i] = 62510;
		}

		scanf("%d", &dummy);
		for(int i=0; i<p-1; i++)
		{
			scanf("%d", &prince[i]);
		}
		scanf("%d%d", &dummy,&dummy);
		for(int i=0; i<q-1; i++)
		{		
			scanf("%d", &princess[i]);
			data[princess[i]] = i+1;
		}
		scanf("%d", &dummy);

		printf("Case %d: %d\n", count++, GetLIS(prince, p-1) + 2);
	}
	return 0;
}