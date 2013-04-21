#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <map>
#include <cmath>
using namespace std;

int n,m;
int vessels[1001];

bool func(int x)
{
    int cont = m;
    int cur = 0;
    for(int j=0; j<n; j++)
    {
       // cout<<cont<<" "<<vessels[j]<<" "<<cur<<endl;
        if(cur+vessels[j] <=x)
        {
            cur = cur + vessels[j];
        }
        else if(vessels[j]<=x)
        {
            cur = vessels[j];
            cont--;
            if(cont==0)
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    return true;
}

int main()
{
    while(scanf("%d%d", &n, &m) != EOF)
    {
        memset(vessels, 0, sizeof(int)*n);
        for(int i=0; i<n; i++)
        {
            scanf("%d",&vessels[i]);
        }
        int l=1, h=1000000000;
        int m;
        int k=50;
        int ans;
        //cout<<func(8)<<endl;
        while(l<h && k)
        {
            //cout<<l<<" "<<m<<" "<<h<<endl;
            k--;
            m = (l+h)/2;
            if(func(m))
            {
                ans = m;
                h = m;
            }
            else
            {
                l = m;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
