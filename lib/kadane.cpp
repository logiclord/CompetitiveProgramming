#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include<climits>

using namespace std;


void kadane(int A[], int n)
{
    int maxe = INT_MIN;
    int maxc = 0;
    int mi=0,mj=0,k=0;
    int maxele = INT_MIN;
    for(int i=0; i<n; i++)
    {
        if(maxc+A[i] > A[i])
        {
            maxc += A[i];
        }
        else
        {
            maxc = A[i];
            k = i;
        }
        if(maxc > maxe)
        {
            mi = k;
            mj = i;
            maxe = maxc;
            cout<<"found end at "<<i<<endl;
        }
    }
    cout<<maxe<<"\n";
    for(int i=mi;i<=mj;i++)
    {
        cout<<A[i]<<" ";
    }
}

int main()
{
    cout<<'Q' - 'A' + 1;
    int a[] = {-2, -1, -3, -4, -1, -2, -1, -5, -4};
    kadane(a, sizeof(a)/sizeof(int));
    return 0;
}
