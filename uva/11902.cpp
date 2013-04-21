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

int n,m;
int data[101][101];
int dfs_state[101][101];
bool dominant[101][101];

void DFS(int u, int x)
{
    dfs_state[u][x] = 1;
    if(x!=0)
    {
        dominant[x][u] = false;
    }
    else
    {
        for(int k=0 ; k<n; k++)
        {
            dominant[k][u] = true;
        }
    }
    for(int i=0; i<n; i++)
    {
        if(data[u][i] && dfs_state[i][x] == -1 && i!=x)
        {
            DFS(i,x);
        }
    }
}

int main()
{
    int t, cas = 1;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                scanf("%d",&data[i][j]);
                dominant[i][j] = false;
                dfs_state[i][j] = -1;
            }
        }
        for(int i=0; i<n; i++)
        {
            DFS(0,i);
        }
        printf("Case %d:\n",cas);
        printf("+");
        for(int i=1; i<2*n; i++)
        {
            printf("-");
        }
        printf("+\n");

        for(int i=0; i<n; i++)
        {
            printf("|");
            for(int j=0; j<n; j++)
            {
                char tp = (dominant[i][j] == 1 ? 'Y' : 'N');
                printf("%c|",tp);
            }
            printf("\n+");
            for(int i=1; i<2*n; i++)
            {
                printf("-");
            }
            printf("+\n");
        }
        cas++;
    }
}
