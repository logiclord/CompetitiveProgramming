#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <set>
#include <vector>
#include<map>
#include<cstdio>

using namespace std;


map<string, vector<string> > data;
map<string, int> dfs_num;
map<string, int> dfs_low;
map<string, string> parents;
set<string> c;
int rchild = 0;
int timer;

void dfs(string cur, string root)
{
    dfs_low[cur] = dfs_num[cur] = timer++;
    for(vector<string>::iterator it = data[cur].begin(); it != data[cur].end(); it++)
    {
        if(dfs_num.find(*it) == dfs_num.end())
        {
            if(root == cur)
            {
                rchild++;
            }
            parents[*it] = cur;
            dfs(*it, root);
            dfs_low[cur] = min(dfs_low[cur], dfs_low[*it]);
            if(dfs_low[*it] >= dfs_num[cur])
            {
                //cout<<"found "<<cur<<" "<<dfs_low[*it]<<" "<<dfs_num[cur]<<endl;
                c.insert(cur);
            }
        }
        else if(parents[cur] != *it)
        {
            dfs_low[cur] = min(dfs_low[cur], dfs_num[*it]);
        }
    }
}

int main()
{
    int n, m, testcase = 1;
    while(scanf("%d",&n) && n)
    {
        timer = 0;
        string tmp, tmp2;
        data.clear();
        dfs_num.clear();
        dfs_low.clear();
        parents.clear();
        c.clear();
        for(int i=0; i<n; i++)
        {
            vector<string> v;
            cin>>tmp;
            data.insert(make_pair(tmp, v));
        }
        cin>>m;
        for(int i=0; i<m; i++)
        {
            cin>>tmp>>tmp2;
            data[tmp].push_back(tmp2);
            data[tmp2].push_back(tmp);
        }
        for(map<string, vector<string> >::iterator it = data.begin(); it != data.end(); it++)
        {
            if(dfs_num.find(it->first) == dfs_num.end())
            {
                rchild = 0;
                dfs(it->first,it->first);
                if(rchild > 1)
                {
                    c.insert(it->first);
                }
                else
                {
                    c.erase(it->first);
                }
            }
        }
        if(testcase != 1)
            printf("\n");
        printf("City map #%d: %d camera(s) found\n",testcase,c.size());
        for(set<string>::iterator it = c.begin(); it!=c.end(); it++)
        {
            cout<<*it<<endl;
        }
        testcase++;
    }
    return 0;
}
