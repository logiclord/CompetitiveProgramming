#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

void merge(int arr[],int s,int m, int e, int temp[])
{
    int i = s, j = m;
    int k=0;
    while ((i <= m - 1) && (j <= e))
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
        }
    }

    while (i <= m - 1)
        temp[k++] = arr[i++];


    while (j <= e)
        temp[k++] = arr[j++];

    for(int p=0;p<k;p++)
    {
        arr[s+p] = temp[p];
    }
}

void mergeSort(int arr[], int n)
{
    int * w = (int *)calloc( n, sizeof(int) );
    for(int i=1; i<n; i=i*2)
    {
        for(int j=0; j<(n-i); j= j+ 2*i)
        {
           //cout<<j<<" "<<j+1<<" "<<j + 2*i - 1<<endl;
            merge(arr,j,min(j + i, n), min(n-1,j + 2*i - 1), w);
        }
    }
	free(w);
}

/* Driver progra to test above functions */
int main()
{
    int t;
    int original[10000];
    while(scanf("%d",&t) != EOF)
    {
        for(int i=0; i<t; i++)
        {
            scanf("%d",&original[i]);
        }
        mergeSort(original, t);

        for(int i=0; i<t; i++)
        {
            printf("%d ",original[i]);
        }

        printf("\n");
    }
    return 0;
}
