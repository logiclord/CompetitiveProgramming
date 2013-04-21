#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <set>
#include <vector>
#include<map>
#include<cstdio>
#include<stack>
#include<cstring>
using namespace std;


vector<vector<int> > data;
int dfs_low[2001];
int dfs_num[2001];
bool visited[2001];
int SCC = 0;
vector<int> st;
int num = 0;

void dfs(int cur)
{
    st.push_back(cur);
    visited[cur] = true;
    dfs_num[cur] = dfs_low[cur] = num++;
    for(vector<int>::iterator it = data[cur].begin(); it!=data[cur].end(); it++)
    {
        if(dfs_num[*it] == -1)
        {
            dfs(*it);
        }
        if(visited[*it])
        {
            dfs_low[cur] = min(dfs_low[cur], dfs_low[*it]);
        }
    }

    if(dfs_num[cur] == dfs_low[cur] )
    {
        SCC++;
        while(1)
        {
            int vt = st.back();
            visited[vt] = false;
            st.pop_back();
            if(cur==vt)
                break;
        }
    }
}

int main()
{
    int n, m, testcase = 1;
    while(scanf("%d%d",&n,&m) && (n|m))
    {
        num = 0;
        int x,y,z;
        memset(dfs_low, -1, sizeof(dfs_low));
        memset(dfs_num, -1, sizeof(dfs_num));
        memset(visited, 0, sizeof(visited));
        st.clear();

        SCC = 0;
        data.clear();
        for(int i=0; i<=n; i++)
        {
            vector<int> tmp;
            data.push_back(tmp);
        }

        for(int i=1; i<=m; i++)
        {
            scanf("%d%d%d",&x,&y,&z);
            data[x].push_back(y);
            if(z>1)
            {
                data[y].push_back(x);
            }
        }
        for(int i=1; i<=n; i++)
        {
            if(dfs_num[i]== -1)
            {
                dfs(i);
            }
        }

        if(SCC == 1)
        {
            printf("1\n");
        }
        else
        {
            printf("0\n");
        }
    }
    return 0;
}
