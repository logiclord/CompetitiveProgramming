#include<cstdio>
#include<vector>
#include<climits>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cctype>
#include<iostream>
#include<cstdlib>
#include<set>

using namespace std;

long long data[1000][1000];


long long  counts(int n, int k, int m)
{
    if(k==0 || n<=0)
        return 0;
    if(k==1 && m>=n)
        return 1;
    if(k==1 && m<n)
        return 0;

    if(data[n][k]!=-1)
        return data[n][k];

    long long  total = 0;
    for(int i=1;i<=m;i++)
    {
        total += counts(n-i,k-1,m);;
    }

    return (data[n][k]=total);
}

int main()
{
    int n,k,m;
    while(cin>>n>>k>>m)
    {
        memset(data, -1, sizeof(data));
        cout<<counts(n,k, m)<<endl;
    }
}
