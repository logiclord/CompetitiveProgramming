#include <map>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int m,n,r,cur;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        map<int,vector<int> > hash;
        for(int i=1; i<=m; i++)
        {
            scanf("%d",&cur);
            if(hash.find(cur) == hash.end())
            {
                vector<int> v;
                hash.insert(make_pair(cur,v));
            }
            hash[cur].push_back(i);
        }
        for(int i=1; i<=n; i++)
        {
            scanf("%d%d",&r,&cur);
            if(hash.find(cur) != hash.end() && hash[cur].size()>= r)
            {
                printf("%d\n",hash[cur][r-1]);
            }
            else
            {
                printf("0\n");
            }
        }
    }
    return 0;
}

