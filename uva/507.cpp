#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include<climits>

using namespace std;

int data[101][101];

long long kadane(int A[], int n, int &p, int &q)
{
    long long  maxe = INT_MIN;
    long long  maxc = 0;
    int tmp = 0;
    for(int i=0; i<n; i++)
    {
       // cout<<A[i]<<" "<<maxe<<" "<<maxc<<endl;
        if(maxc+A[i] >=0 )
        {
            maxc = A[i] + maxc;
        }
        else
        {
            maxc = 0;
            tmp = i+1;
        }
        if(maxe<maxc)
        {
            maxe = maxc;
            p = tmp;
            q = i;
        }
        else if(maxe == maxc)
        {
          //  cout<<"hh "<<p<<" "<<q<<" "<<tmp<<" "<<i<<endl;
            if(q-p < i-tmp || (q-p==i-tmp && p>tmp) )
            {
                p = tmp;
                q = i;
            }
        }
    }
    return maxe;
}

int main()
{
    int n;
    while(scanf("%d",&n) != EOF)
    {
        for(int i=1; i<= n; i++)
        {
            int k;
            int A[21000];
            int p,q;
            scanf("%d",&k);
            k--;
            for(int j=0; j<k; j++)
            {
                scanf("%d",&A[j]);
            }
            if(kadane(A, k, p, q) != 0)
            {
                p++;
                q++;
                q++;
                printf("The nicest part of route %d is between stops %d and %d\n",i,p,q);
            }
            else
            {
                printf("Route %d has no nice parts\n",i);
            }
        }
    }
    return 0;
}
