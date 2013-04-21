#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include<climits>

using namespace std;

int data[101][101];

int kadane(int A[], int n)
{
    int maxe = INT_MIN;
    int maxc = 0;
    for(int i=0; i<n; i++)
    {
        maxc = max(maxc+A[i], A[i]);
        maxe = max(maxe, maxc);
    }
    return maxe;
}

int kadane2D(int n)
{
    int maxc = INT_MIN;
    int maxe = INT_MIN;

    for(int i=0; i<n; i++)
    {
        int A[101] = {0};
        for(int j=i; j<n; j++)
        {
            for(int k=0; k<n; k++)
            {
                A[k] += data[k][j];
            }
            maxc = kadane(A,n);
            maxe = max(maxe,maxc);
        }
    }
    return maxe;
}

int main()
{
    int n;
    while(scanf("%d",&n) != EOF)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                scanf("%d",&data[i][j]);
            }
        }
        printf("%d\n",kadane2D(n));
    }
    return 0;
}
