#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>

using namespace std;


bool comp(const int a, const int b)
{
    return a>b;
}

int main()
{
    int n,d,r;
    while(scanf("%d%d%d",&n,&d,&r) && (n|d|r))
    {
        vector<int> v1,v2;
        int tmp;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&tmp);
            v1.push_back(tmp);
        }
        for(int i=0;i<n;i++)
        {
            scanf("%d",&tmp);
            v2.push_back(tmp);
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end(), comp);
        int sum = 0;
        for(int i=0;i<n;i++)
        {
            if(v1[i]+v2[i]>d)
            sum += (v1[i]+v2[i]-d)*r;
        }
        printf("%d\n",sum);
    }
    return 0;
}
