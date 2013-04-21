#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include<climits>

using namespace std;

int num;
int data[1000][1000];

int kadane(int A[], int c, int n)
{
    int maxe = INT_MIN;
    int maxc = 0;
    for(int i=c; i<c+n; i++)
    {
        maxc = max(maxc+A[i%n], 0);
        maxe = max(maxe, maxc);
    }
    return maxe;
}

int kadane2D()
{
    int n = num;
    int maxc = INT_MIN;
    int maxe = INT_MIN;

    for(int i=0; i<n; i++)
    {
        int A[1000] = {0};
        for(int j=i; j<i+n; j++)
        {
           // cout<<i<<" "<<j<<endl;
            for(int k=0; k<n; k++)
            {
              //  cout<<"-- "<<k<<endl;
                A[k] += data[k][j%num];
            }
            for(int k=0;k<n;k++)
            {
               // cout<<"--1- "<<k<<endl;
                maxc = kadane(A,k,n);
                //cout<<i<<" "<<j<<" "<<k<<" "<<maxc<<endl;
                maxe = max(maxe,maxc);
            }
        }
    }
    return maxe;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&num);
        for(int i=0; i<num; i++)
        {
            for(int j=0; j<num; j++)
            {
                scanf("%d",&data[i][j]);
            }
        }
        printf("%d\n",kadane2D());
    }
    return 0;
}
