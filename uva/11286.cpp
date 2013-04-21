#include <map>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;


int main()
{
    int t;
    while(scanf("%d",&t) && t)
    {
        int tmp, maxi = -1;
        map<vector<int>, int> hash;
        vector<vector<int> > data;
        for(int i=0; i<t; i++)
        {
            vector<int> v;
            for(int j=0; j<5; j++)
            {
                scanf("%d",&tmp);
                v.push_back(tmp);
            }
            sort(v.begin(),v.end());
            data.push_back(v);
            hash[v]++;
            maxi = max(maxi, hash[v]);
        }
        int total = 0;
        for(vector<vector<int> >::iterator it = data.begin(); it!= data.end(); it++)
        {
            if(hash[*it] == maxi)
            {
                total++;
            }
        }
        printf("%d\n",total);
    }
    return 0;
}

