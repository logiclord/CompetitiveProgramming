#include<cstdio>
#include<vector>
#include<climits>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cctype>
#include<iostream>

using namespace std;

long long dpData[5][30001];
int deno[] ={1, 5, 10, 25, 50};

long long countWays(int t, int n)
{
    if(n<0)
    {
        return 0;
    }
    else if(n==0)
    {
        return (dpData[t][n]=1);
    }
    else if(t==5)
    {
        return 0;
    }
    else if(dpData[t][n]!=-1)
    {
        return dpData[t][n];
    }
    else
    {
        return (dpData[t][n] = countWays(t+1,n) + countWays(t,n-deno[t]));
    }
}

int main()
{
    int n;
    memset(dpData, -1, sizeof(dpData));

    while(scanf("%d",&n)!=EOF)
    {
        long long count = countWays(0,n);
        if(count == 1)
        {
            printf("There is only 1 way to produce %d cents change.\n",n);
        }
        else
        {
            printf("There are %lld ways to produce %d cents change.\n",count,n);
        }
    }
    return 0;
}

