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
    int cur, id, dur;
    comp()
    {


    }
    comp(int id, int dur)
    {
        this->cur = dur;
        this->id = id;
        this->dur = dur;
    }

};

bool operator<(const comp& a, const comp& b)
{
    if(a.cur != b.cur)
    {
        return a.cur> b.cur;
    }
    return a.id > b.id;
}

int main()
{
    priority_queue<comp> pq;
    char str[100];
    int id, dur, k;
    while(scanf("%s",str) && str[0]!='#' && scanf("%d%d",&id,&dur))
    {
       // cout<<str<<id<<" "<<dur<<dur;
        struct comp cp(id,dur);
        pq.push(cp);
    }
    scanf("%d",&k);
    for(int i=0; i<k; i++)
    {

        comp cp = pq.top();
        printf("%d\n",cp.id);
        pq.pop();
        cp.cur = cp.cur + cp.dur;
        pq.push(cp);
    }
    return 0;
}
