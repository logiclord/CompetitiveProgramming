#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int,char> >v;
int n,d;

bool func(int x)
{
    if(x>=d)
        return true;

    int j=0,i, pos = 0;
    int hash[110] = {0};

    for(i=0; i<n; i=j)
    {
        while(v[j].first <= (pos+x) && j<n)
        {
            j++;
        }
        if(i==j)
        {
            return false;
        }
        else if(pos+x>=d)
        {
            break;
        }
        else if(v[j-1].first <= (pos+x))
        {
            pos = v[j-1].first;
            if(v[j-1].second == 'S')
            {
                hash[j-1] = 1;
            }
        }
    }

    if(pos+x<d)
    {
        return false;
    }

    pos = d;
    i = j = n-1;

    int k;

    j = n-1;
    for(i=n-1; i>=0; i=j)
    {
        k = -1;
        while(v[j].first >= (pos-x) && j>=0)
        {
            if(hash[j]==0)
            {
                k = j;
            }
            j--;
        }
        if(k == -1)
		{
            return false;
        }
        else if(v[k].first >= (pos-x))
        {
            pos = v[k].first;
        }
    }

    if(pos-x>0)
    {
        return false;
    }


    return true;
}

int main()
{
    int t, q=1;
    scanf("%d", &t);
    while(t--)
    {
        int p;
        char c;
        scanf("%d%d",&n,&d);
        for(int i=0; i<n; i++)
        {
            getchar();
            scanf("%c-%d",&c,&p);
            v.push_back(make_pair(p,c));
        }
        sort(v.begin(), v.end());
        int l=1, h=d+1;
        int m;
        int k=50;
        int ans;
         while(l<h && k)
         {
             m = (l+h)/2;
             k--;
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
         printf("Case %d: %d\n",q,ans);
         q++;
         v.clear();

    }
    return 0;
}

