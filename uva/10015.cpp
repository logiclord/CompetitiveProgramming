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
#include <map>
using namespace std;

struct node
{
    int val;
    node * ptr;
};


vector<int> pri;
int lastStanding(int t)
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
    int k=0;
    start = last;
    while(start->ptr != start)
    {
       // cout<<start->val<<endl;
        //cout<<last->val<<endl;

        int target = pri[k]%(t-k);
        if(!target)
         target = (t-k);
        for(int i=1; i<=target; i++)
        {
            last = start;
            start = start->ptr;
        }
       // cout<<"--deleting--"<<start->val<<" "<<t-k<<" #"<<pri[k]%(t-k)<<endl;
        last->ptr = start->ptr;
        delete(start);
        start = last;
        k++;
        //  cout<<endl;
    }
    return start->val;
}

void sieve(int n)
{
    bool *prime =new bool[n+1];
    memset(prime, true, sizeof(bool) *(n+1));
    prime[0]=false;
    prime[1]=false;
    int m= sqrt(n);

    for (int k=4; k<=n; k+=2)
        prime[k]=false;

    for (int i=3; i<=m; i=i+2)
        if (prime[i])
            for (int k=i*i; k<=n; k+=i)
                prime[k]=false;

    for(int i=2; i<=n; i++)
    {
        if(prime[i])
            pri.push_back(i);
    }
}


int main()
{
    int t;
    int hash[4000] = {0};
    scanf("%d",&t);
    sieve(40000);
    while(t)
    {
        if(hash[t] == 0)
        {
            hash[t] = lastStanding(t);
        }
        printf("%d\n", hash[t] );
        scanf("%d",&t);
    }
    return 0;
}





