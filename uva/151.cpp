#include <cstdio>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <set>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <deque>
using namespace std;

struct node
{
    int val;
    node * ptr;
};

int lastStanding(int offset, int t)
{
    int size  = t;
    node *start = NULL;
    node *last = NULL;

    if( t>0)
    {
        last = new node;
        last->val = t;
        last->ptr = start;
        start = last;
    }
    // cout<<last-> val<< endl;
    for(int i=t-1; i>0 ; i--)
    {
        node * cur = new node;
        cur->val = i;
        cur->ptr = start;
        start = cur;
    }
    if(last!=NULL)
    {
        last->ptr = start;
    }

    /*
        node *cur = last->ptr;
        cout<<cur->val<<endl;
        cur = cur ->ptr;
        while(cur != start)
        {
            cout<<cur->val<<endl;
            cur = cur  -> ptr;
        }
    */
    while(start->ptr != start)
    {
        //cout<<start->val<<endl;
        //cout<<last->ptr->val<<endl;
        last->ptr = start->ptr;
        delete(start);
        start = last;
        for(int i=1; i<=offset; i++)
        {
            if(start)
            {
                //cout<<start->val<<"\t";
                last = start;
                start = start->ptr;
            }
        }
        //  cout<<endl;
    }
    return start->val;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t)
    {
        int dim = 0;

        for(int i=1; i<=t; i++)
        {
            if(lastStanding(i,t) == 13)
            {
                dim = i;
                break;
            }
        }

        printf("%d\n",dim);
        scanf("%d",&t);
    }
    return 0;
}





