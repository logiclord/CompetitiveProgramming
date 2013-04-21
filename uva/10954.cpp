#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

struct comp
{
    bool operator ()(const int a, const int b)
    {
        return a>b;
    }
};

int main()
{
    int t;
    while(scanf("%d",&t) && t)
    {
        int tmp;
        priority_queue<int, vector<int>, comp> pq;
        for(int i=0; i<t; i++)
        {
            scanf("%d",&tmp);
            pq.push(tmp);
        }
        long long cost = 0;
        while(!pq.empty())
        {
            int a = pq.top();
            pq.pop();
            if(pq.empty())
                break;
            int b = pq.top();
            pq.pop();
            pq.push(a+b);
            cost += a+b;
        }
        printf("%lld\n",cost);
    }
    return 0;
}
