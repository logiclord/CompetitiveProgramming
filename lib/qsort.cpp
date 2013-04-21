#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include<climits>

using namespace std;

int partition(int A[], int l, int r)
{
    int up = l;
    int down = r;
    int pv = A[l];
    while(up<down)
    {
        while(A[up]<=pv && up<down)
        {
            up++;
        }
        while(A[down]>pv)
        {
            down--;
        }
        if(up<down)
        {
            swap(A[up], A[down]);
        }
    }
    swap(A[down],A[l]);
    return down;
    /*
        int st = l;
        int pv = A[r];
        for(int i=l;i<r; i++)
        {
            if(A[i]<pv)
            {
                swap(A[st], A[i]);
                st++;
            }
        }
        swap(A[st], A[r]);
        return st;
    */
}

void quickSort(int A[], int l, int r)
{
    if(l<r)
    {
        int p = partition(A, l, r);
        cout<<l<<" "<<r<<" "<<p<<" "<<A[p]<<endl;
        quickSort(A, l, p-1);
        quickSort(A, p+1, r);
    }
}

int main()
{
    int a[] = {-2, -1, 3, -4, -1, 2, -1, 5, -4, 45 , 0 ,569 ,3455, 3, -456};
    for(int i=0; i<sizeof(a)/sizeof(int); i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    quickSort(a,0, sizeof(a)/sizeof(int)-1);
    for(int i=0; i<sizeof(a)/sizeof(int); i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
