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
        map<int, vector<pair<int,int> > > hash;
        for(int i=1; i<=n; i++)
        {
            vector<pair<int,int> > v;
            hash.insert(make_pair(i,v));
        }
        for(int i=1; i<=m; i++)
        {
            vector<int> tp;
            scanf("%d",&r);
            for(int j=1; j<=r; j++)
            {
                scanf("%d",&cur);
                tp.push_back(cur);
            }
            for(vector<int>::iterator it = tp.begin(); it!=tp.end(); it++)
            {
                scanf("%d",&cur);
                hash[*it].push_back(make_pair(i,cur));
            }
        }
        printf("%d %d\n",n,m);
        for(int i=1; i<=n; i++)
        {
            printf("%d",hash[i].size());
            for(vector<pair<int,int> >::iterator it = hash[i].begin(); it!=hash[i].end(); it++)
            {
                printf(" %d",it->first);
            }
            printf("\n");
            bool firstCase = true;
            for(vector<pair<int,int> >::iterator it = hash[i].begin(); it!=hash[i].end(); it++)
            {
                if(!firstCase)
                {
                    printf(" ");
                }
                firstCase = false;
                printf("%d",it->second);
            }
            printf("\n");
        }
    }
    return 0;
}

