#include<set>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<cstring>
#include<cctype>
#include<string>
#include<map>
#include<sstream>
#include<queue>
using namespace std;

#include<set>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<cstring>
#include<cctype>
#include<string>
#include<map>
#include<sstream>
#include<queue>
#include<cmath>
using namespace std;

void permute(int arr[], int i, int num)
{
    if(num == i)
    {
        for(int j=0;j<=num;j++)
        {
            cout<<arr[j]<<" ";
        }
        cout<<endl;
    }
    else
    {
        for(int j=i; j<=num; j++)
        {
            swap(arr[j], arr[i]);
            permute(arr, i+1, num);
            swap(arr[j], arr[i]);
        }
    }
}

// Lexicographical non-repeating permutation

void permute2(int data[], int num, int used[], int numUsed, int permuted[])
{
    if(numUsed == num)
    {
        for(int j=0;j<num;j++)
        {
            cout<<permuted[j]<<" ";
        }
        cout<<endl;
    }
    else
    {
        for(int index=0; index<num; index++)
        {
            if(index>0 && data[index]== data[index-1] && used[index-1]==0)
                continue;
            if(used[index] == 0)
            {
                used[index] = 1;
                permuted[numUsed] = data[index];
                permute2(data, num, used, numUsed+1, permuted);
                used[index] = 0;
            }
        }
    }
}


int main()
{
    int data[] = {2,1,1,3,2, 2};
    int used[100] = {0};
    int permuted[100];
    sort(data, data +  sizeof(data)/sizeof(int));
    permute2(data, sizeof(data)/sizeof(int), used, 0, permuted);
    return 0;
}





