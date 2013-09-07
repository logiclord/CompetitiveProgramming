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
#include<sstream>
#include<climits>
using namespace std;

/*
Suffix Array
*/

int * getLCP(const int *SA, const char * str, const int len)
{
	int *lcp = new int[len];
	int *plcp = new int[len];
	int *phi = new int[len];

	phi[SA[0]] = -1;
	for(int i=1; i<len; i++)
	{
		phi[SA[i]] = SA[i-1];
	}

	for(int i=0, L = 0; i<len; i++)
	{
		if(phi[i]==-1)
		{
			plcp[i] = 0;
		}
		else
		{
			while(str[i+L] == str[phi[i]+L])
			{
				L++;
			}
			plcp[i] = L;
			L = max(L-1, 0);
		}
	}

	for(int i=1; i<len; i++)
	{
		lcp[i] = plcp[SA[i]];
	}
	lcp[0] = 0;
	delete [] phi;
	delete [] plcp;
	return lcp;
}


void countSort(int k, int *SA, int * RA, int *TSA, int len)
{
	int c[10001] = {0};
	for(int i=0;i<len;i++)
	{
		c[i+k<len?RA[i+k]: 0]++;
	}

	for(int i=1;i<10001;i++)
	{
		c[i] += c[i-1];
	}
	for(int i=len-1; i>=0; i--)
	{
		TSA[--c[SA[i]+k<len ? RA[SA[i]+k]: 0]]= SA[i];
	}

	for(int i=0; i<len; i++)
	{
		SA[i] = TSA[i];
	}
}

int *getSuffixArray(const char * str, int len)
{
	int *SA = new int[len];
	int *RA = new int[len];
	int *TRA = new int[len];
	int *TSA = new int[len];

	for(int i=0;i<len; i++)
	{
		SA[i] = i;
		RA[i] = str[i]-'.';
	}

	for(int k=1; k<len; k=k<<1)
	{
		countSort(k, SA, RA, TSA, len);
		countSort(0, SA, RA, TSA, len);
		int count = 1;
		TRA[SA[0]] = count;
		for(int i=1;i<len; i++)
		{
			TRA[SA[i]] = ((RA[SA[i]] == RA[SA[i-1]] && RA[SA[i]+k] == RA[SA[i-1]+k]) ? count : ++count);
		}
		for(int i=0; i<len; i++)
		{
			RA[i] = TRA[i];
		}
	}

	delete [] RA;
	delete [] TSA;
	delete [] TRA;

	return SA;
}

int main()
{
	int t;
	scanf("%d",&t);
	getchar();
	char str[100005];
	while(gets(str))
	{
		int len =strlen(str);
		int maxi = 0;
		int sa = 0;
		int * SA =NULL , *lcp = NULL;
		if(len>0)
		{
			SA = getSuffixArray(str, len);
			lcp = getLCP(SA, str, len);
			/*
			for(int i=0; i<len; i++)
			{
				cout<<lcp[i]<<"\t"<<SA[i]<<"\t"<<(str + SA[i])<<endl;
			}
			*/
			for(int i=0; i<len; i++)
			{
				if(lcp[i] > maxi)
				{
					sa = i;
					maxi = lcp[i];
				}
			}
		}
		if(maxi==0)
		{
			printf("No repetitions found!\n");
		}
		else
		{
			int count = 2;
			for(int i=sa+1; i<len && lcp[i]>=maxi; i++)
			{
				count++;
			}
			for(int i=0;i <maxi; i++)
			{
				cout<<str[SA[sa]+i];
			}
			cout<<" "<<count<<endl;
		}
	}

	return 0;
}
