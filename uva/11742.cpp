#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int aa[21];
int ab[21];
int ac[21];
int n,m;
int output;

void permute(int arr[],int n,int i)
{
    if(i==n)
    {
        bool consider = true;
        int indexHash[50] = {0};
        for(int j=0; j<n; j++)
        {
            indexHash[arr[j]] = j;
        }

        for(int i=0; i<m; i++)
        {
            if((ac[i]>0 && abs(indexHash[aa[i]]-indexHash[ab[i]])>ac[i]) || (ac[i]<0 && abs(indexHash[aa[i]]-indexHash[ab[i]])< abs(ac[i])))
            {
                consider = false;
                break;
            }
        }

        if(consider)
        {
            /*
            for(int j=0; j<n; j++)
            {
                cout<<arr[j]<<" ";
            }
            cout<<endl;
            */
            output++;
        }
    }
    else
    {
        for(int j=i; j<n; j++)
        {
            swap(arr[i],arr[j]);
            permute(arr,n,i+1);
            swap(arr[i],arr[j]);
        }
    }
}

int main()
{
    while(scanf("%d%d",&n,&m) && (m|n))
    {
        int input[10];
        output = 0;
        for(int i=0; i<n; i++)
        {
            input[i] = i;
        }
        for(int i=0; i<m; i++)
        {
            scanf("%d%d%d",&aa[i],&ab[i],&ac[i]);
        }
        permute(input,n,0);
        printf("%d\n",output);
    }
    return 0;
}
