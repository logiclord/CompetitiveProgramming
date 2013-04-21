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
int wind[1000][1000];
int n,p;


int generateCost(int al, int dis)
{
    if(dis== p && al==0)
    {
        return 0;
    }
    else if(al<0 || al>9 ||dis==p)
    {
        return 8888888;
    }
    if(data[al][dis]!=-1)
    {
        return data[al][dis];
    }
    int total = INT_MAX;
    total = min(total, 20-wind[al][dis]+generateCost(al-1,dis+1));
    total = min(total, 30-wind[al][dis]+generateCost(al,dis+1));
    total = min(total, 60-wind[al][dis]+generateCost(al+1,dis+1));
    return (data[al][dis] = total);
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        p = n/100;
        for(int i=9; i>=0; i--)
        {
            for(int j=0; j<p; j++)
            {
                scanf("%d",&wind[i][j]);
                data[i][j] = -1;
            }
        }
        cout<<generateCost(0,0)<<"\n\n";
/*
        for(int i=9; i>=0; i--)
        {
            for(int j=0; j<p; j++)
            {
                cout<<data[i][j]<<"\t";
            }
            cout<<endl;
        }
*/
    }
}
