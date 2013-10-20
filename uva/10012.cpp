#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<fstream>
using namespace std;
int number;
double area;
double r[10];
int vis[10];
int b[10];
double maxr;

double rec_area()
{
	double tmpr[10];
	tmpr[0]=r[b[0]];
	for(int i=1; i<number; i++)
	{
		double l=0.0;
		for(int j=i-1; j>=0; j--)
		{
			double t=sqrt((r[b[i]]+r[b[j]])*(r[b[i]]+r[b[j]])-(r[b[i]]-r[b[j]])*(r[b[i]]-r[b[j]]));
			if(tmpr[j]+t>l)l=tmpr[j]+t;
		}
		if(l<r[b[i]])l=r[b[i]];
		tmpr[i]=l;
	}
	double max=0.0;
	for(int i=0; i<number; i++)
	{
		if(max<tmpr[i]+r[b[i]])max=tmpr[i]+r[b[i]];
	}
	return max>maxr? max:maxr;
}

int main()
{
	int ncase;
	cin>>ncase;
	while(ncase--)
	{
		cin>>number;
		maxr=0.0;
		for(int i=0; i<number; i++)
		{
			cin>>r[i];
			if(maxr<r[i])maxr=r[i];
			b[i] = i;
		}
		memset(vis,0,sizeof(vis));
		area=rec_area();
		while(next_permutation(b,b+number))
		{
			double tmp=rec_area();
			if(tmp<area)area=tmp;
		}
		printf("%.3lf\n",area);
	}
	return 0;
}