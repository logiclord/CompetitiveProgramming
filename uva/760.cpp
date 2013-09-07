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

using namespace std;

/*
Suffix Array
*/

int * getLCP(char *str, int *SA, int size)
{
	int *lcp = new int[size];
	int *plcp = new int[size];
	int *phi = new int[size];

	phi[SA[0]] = -1;
	for(int i=1; i<size; i++)
	{
		phi[SA[i]] = SA[i-1];
	}

	for(int i=0, L = 0; i<size; i++)
	{
		if(phi[i] == -1)
		{
			plcp[i] = 0;
			continue;
		}
		while(str[i + L] == str[phi[i] + L])
			L++;
		plcp[i] = L;
		L = max(L-1,0);
	}

	for(int i=0;i<size; i++)
	{
		lcp[i] = plcp[SA[i]];
	}
	delete [] plcp;
	delete [] phi;
	return lcp;
}

void countSort(int k, int size, int *RA, int *TSA, int *SA)
{
	int c[700] = {0};
	for(int i=0;i<size; i++)
	{
		c[i + k <size ?RA[i+k]: 0]++;
	}
	for(int i=1;i<700; i++)
	{
		c[i] += c[i-1];
	}

	for(int i=size-1; i>=0; i--)
	{
		TSA[--c[SA[i]+k <size ? RA[SA[i]+k] : 0]] = SA[i];
	}

	for(int i=0;i<size;i++)
	{
		SA[i] = TSA[i];
	}
}

int * createSuffixArray(char *T, int size)
{
	int *SA = new int[size];
	int *TSA = new int[size];
	int *RA = new int[size];
	int *TRA = new int[size];

	for(int i=0;i<size;i++)
	{
		SA[i] = i;
		RA[i] = T[i];
	}

	for(int k=1; k<size; k=k<<1)
	{
		countSort(k,size, RA, TSA, SA);
		countSort(0, size, RA, TSA, SA);
		TRA[SA[0]] = 1;
		int count = 1;
		for(int i=1;i<size;i++)
		{
			if(RA[SA[i]] == RA[SA[i-1]] && RA[SA[i] + k] == RA[SA[i-1] + k])
			{
				TRA[SA[i]] = count;
			}
			else
			{
				TRA[SA[i]] = ++count;
			}
		}
		for(int i=0;i<size;i++)
		{
			RA[i] = TRA[i];
		}
	}
	delete [] TRA;
	delete [] TSA;
	delete [] RA;

	return SA;
}

int main()
{
	char a[301], b[301];
	bool firstTime = false;
	while(gets(a)!=NULL && gets(b)!=NULL)
	{
		if(firstTime)
			printf("\n");
		else
			firstTime = true;
		getchar();
		char c[605];
		int index = 0, nextIndex = 0, firstSize = 0;
		while(a[index])
		{
			c[index] = a[index];
			index++;
		}
		firstSize = index;
		c[index++] = '.';
		while(b[nextIndex])
		{
			c[index++] = b[nextIndex++];
		}
		c[index] = '\0';

		int *SA = createSuffixArray(c, index);
		int *lcp = getLCP(c, SA, index);
		int maxi = 0;
		for(int i=1; i<index; i++)
		{
			if((SA[i] > firstSize && SA[i-1]<firstSize) || (SA[i] < firstSize && SA[i-1]>firstSize))
			{
				maxi = max(maxi, lcp[i]);
			}
			//cout<<lcp[i]<<" "<<c+SA[i]<<endl;
		}

		string hash= "";
		if(maxi==0)
		{
			printf("No common sequence.\n");
		}
		else
		{	
			for(int i=0; i<index; i++)
			{
				if(lcp[i] == maxi && ((SA[i] > firstSize && SA[i-1]<firstSize) || (SA[i] < firstSize && SA[i-1]>firstSize)))
				{
					string cur(c+SA[i], maxi);
					if(cur!=hash)
					{
						hash=cur;
						for(int k=0; k<maxi; k++)
						{
							printf("%c",c[SA[i] + k]);
						}
						printf("\n");

					}
				}
			}
		}

	}
	return 0;
}
