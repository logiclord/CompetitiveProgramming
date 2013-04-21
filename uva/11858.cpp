#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int original[1000005];
int sorted[1000005];
long long  mSort(int arr[], int st, int sz)
{
    long long  inversions = 0;
    if(st<sz)
    {
        int med = (st+sz)/2;
        inversions += mSort(arr, st, med);
        inversions += mSort(arr, med+1, sz);
        int i = st, j= med+1, l = sz;
        int x = 0;

        while(i<=med || j<=l)
        {
            if(i<=med && j<=l)
            {
                if(arr[i]<arr[j])
                {
                    sorted[x] = arr[i];
                    i++;
                }
                else
                {
                    sorted[x] = arr[j];
                    inversions+= med-i+1;
                    j++;
                }
            }
            else if(i<=med)
            {
                sorted[x] = arr[i];
                i++;
            }
            else
            {
                sorted[x] = arr[j];
                j++;
            }
            x++;
        }
        for(int i=0; i<x; i++)
        {
            arr[st+i] = sorted[i];
        }
    }
  //  cout<<st<<" "<<sz<<" "<<inversions<<endl;
    return inversions;
}

long long  mergeSort(int arr[], int size)
{
    return mSort(arr, 0, size-1);
}

/* Driver progra to test above functions */
int main()
{
    int t;
    while(scanf("%d",&t) != EOF)
    {
        for(int i=0; i<t; i++)
        {
            scanf("%d",&original[i]);
        }
        /*
        for(int i=0; i<t; i++)
        {
            printf("%d ",original[i]);
        }
        */
        printf("%lld\n", mergeSort(original, t));
    }
    return 0;
}
