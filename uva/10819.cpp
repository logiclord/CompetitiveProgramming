#include<cstdio>
#include<vector>
#include<climits>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cctype>
#include<iostream>

using namespace std;

int data[101][10300];
int v[101];
int w[101];

/*
int happiness(int index, int n, int w[], int v[], int t)
{
    if(index==t)
    {
        return 0;
    }
    if(n==0)
    {
        return 0;
    }
    if(data[index][n]!=-1)
    {
        return data[index][n];
    }
    if(n < w[index])
    {
        return (data[index][n] = happiness(index+1, n,w,v,t));
    }
    else
    {
        return (data[index][n] = max(happiness(index+1, n-w[index],w,v,t) + v[index], happiness(index+1, n,w,v,t)));
    }
}
*/

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(data, -1, sizeof(data));
        int total = 0;
        for(int i=0; i<m; i++)
        {
            //cout<<data[i][i]<<endl;
            scanf("%d%d",&w[i],&v[i]);
            total += w[i];
        }

        int k = n;
        n += 200;

        for(int i=0; i<=n; i++)
        {
            data[0][i] = 0;
        }

        for(int i=0; i<=m; i++)
        {
            data[i][0] = 0;
        }


        for(int i=1; i<=m; i++)
        {
            //total += w[i-1];
            for(int j=0; j<=min(total,n); j++)
            {
                data[i][j] =  data[i-1][j];
                if(j>=w[i-1])
                {
                    data[i][j] = max(data[i-1][j],data[i-1][j-w[i-1]] + v[i-1]);
                }
            }
        }

        int answer =  0;
        for (int i=0; i<=k; i++)
            answer = max(answer,data[m][i]);
        for (int i=2001; i<=n; i++)
            answer = max(answer,data[m][i]);

        cout<<answer<<endl;
    }
    return 0;
}



