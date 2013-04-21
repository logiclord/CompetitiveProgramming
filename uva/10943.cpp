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

int data[1000][1000];

int counts(int n, int k)
{
    //cout<<n<<end<<
    if(n==0)
        return 1;

    if(n<0 || k<=0)
        return 0;

    if(data[n][k]!=-1)
        return data[n][k];

    int total = 0;
    for(int x=0; x<=n;x++)
    {
        total = (total + counts(n-x,k-1))%1000000;
    }
    return (data[n][k]=total);
}

int main()
{
    int n,k;
    while(cin>>n>>k && (n|k))
    {
        memset(data, -1, sizeof(data));
        cout<<counts(n,k)<<endl;
    }
}
