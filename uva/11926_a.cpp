#include <map>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m) && (n||m))
    {
        //cout<<"--"<<n<<" "<<m<<endl;
        vector<pair<int,int> > v;
        bool correct = true;
        int a,b,c;
        for(int i=0; i<n; i++)
        {
            scanf("%d%d",&a,&b);
            v.push_back(make_pair(a,b));
        }
        for(int i=0; i<m; i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            do
            {
                v.push_back(make_pair(a,b));
                a+=c;
                b+=c;
            }
            while(b<=1000000);
        }
        sort(v.begin(),v.end());
        vector<pair<int,int> >::iterator it=v.begin();
        a = it->first;
        b = it->second;
        it++;
        //cout<<"%%%%%%\n";
        for(; it!=v.end(); it++)
        {
            if(it->first<b)
            {
                correct = false;
                break;
            }
            a = it->first;
            b = it->second;
        }
        if(!correct)
        {
            printf("CONFLICT\n");
        }
        else
        {
            printf("NO CONFLICT\n");
        }
    }
    return 0;
}

