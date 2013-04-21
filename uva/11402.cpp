#include <map>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

int data[1025000];
int segTree[2097153];
int lazyStatus[2097153];

void adjustLazy(int t,int val)
{
    if(lazyStatus[t]==0)
    {
        lazyStatus[t] =  val;
    }
    else                                // case 2 n 3
    {
        if( val == 1) // inverse
        {
            if(lazyStatus[t]==1)
                lazyStatus[t] = 0;
            else if(lazyStatus[t]==2)
                lazyStatus[t] = 3;
            else if(lazyStatus[t]==3)
                lazyStatus[t] = 2;
        }
        else if(val!= 0)
        {
            lazyStatus[t] =  val;
        }
    }
}

void adjustCur(int v, int i, int j)
{
    int cur;
    int left = v*2 + 1;
    int right = left + 1;
    if(lazyStatus[v] == 0)
        cur = segTree[v];
    else if(lazyStatus[v] == 1) //inversion case
        cur = (j-i+1 - segTree[v]);
    else if(lazyStatus[v] == 2) // turn to Buccaneer Pirates
        cur = (j-i+1);
    else if(lazyStatus[v] == 3) //  turn to  Barbary Pirates
        cur = 0;
    if(i!=j)
    {
        adjustLazy(left, lazyStatus[v]);
        adjustLazy(right, lazyStatus[v]);
    }
    segTree[v] = cur;
    lazyStatus[v] = 0;
}


void makeTree(int i,int j, int v)
{
    lazyStatus[v] = 0;
    if(i==j)
    {
        segTree[v] = data[i];
    }
    else
    {
        int mid = (i+j)/2;
        int left = v*2 + 1;
        int right = left + 1;
        makeTree(i, mid, left);
        makeTree(mid+1, j, right);
        segTree[v] = segTree[left] + segTree[right];
    }
}


int query(int i,int j,int l, int r, int v)
{
    //cout<<"^^"<<i<<" "<<j<< " "<<v<<endl;
    int mid = (i+j)/2;
    int left = v*2 + 1;
    int right = left + 1;
    if(j<l || i>r)
    {
        //cout<<"### --"<<segTree[v]<<"\n";
        adjustCur(v, i, j);
        return 0;
    }
    else if(i>=l && j<=r)
    {
        adjustCur(v, i, j);
        return segTree[v];
    }
    else
    {
        adjustCur(v, i, j);
        int p1 = query(i, mid, l, r, left);
        int p2 = query(mid+1, j, l, r, right);
        segTree[v] = segTree[left] + segTree[right];
        //cout<<"--cur2 "<<v<<" "<<segTree[v]<<" "<<lazyStatus[v]<<endl;
        return (p1+p2);
    }
}

void update(int i,int j,int l, int r, int v, int op)
{
    //cout<<"^^"<<i<<" "<<j<< " "<<v<<" "<<op<<endl;
    int mid = (i+j)/2;
    int left = v*2 + 1;
    int right = left + 1;
    if(j<l || i>r)
    {
        adjustCur(v, i, j);
    }
    else if(i>=l && j<=r)
    {
        adjustLazy(v,op);
        adjustCur(v, i, j);
    }
    else
    {
        adjustCur(v, i, j);
        update(i, mid, l, r, left, op);
        update(mid+1, j, l, r, right, op);
        segTree[v] = segTree[left] + segTree[right];
        //cout<<"~~~~"<<v<<" "<<segTree[v]<<endl;
    }
}

int main()
{
    int t,p=1;
    scanf("%d",&t);
    while(t--)
    {
        int m,r;
        long long index = 0;
        char tmp[60];
        scanf("%d",&m);
        for(int i=0; i<m; i++)
        {
            scanf("%d",&r);
            scanf("%s",tmp);
            for(int j=0; j<r; j++)
            {
                for(int k=0; tmp[k]; k++)
                {
                    data[index++] = tmp[k]-'0';
                }
            }
        }

        for(int i=0; i<index; i++)
        {
            //cout<<data[i];
        }
        //cout<<endl;

        makeTree(0, index-1, 0);
        int q, queryID = 1;
        char op;
        int a,b;
        scanf("%d",&q);
        printf("Case %d:\n",p);
        //cout<<"--"<<index<<"\n";
        while(q--)
        {
            getchar();
            scanf("%c%d%d",&op,&a,&b);
            //cout<<"!!!!!"<<op<<" "<<a<<" "<<b<<endl;
            if(op == 'S')
            {
                printf("Q%d: %d\n",queryID,query(0, index-1,a,b,0));
                queryID++;
            }
            else if(op == 'I')
            {
                update(0, index-1,a,b,0,1);
            }
            else if(op == 'E')
            {
                update(0, index-1,a,b,0,3);
            }
            else
            {
                update(0, index-1,a,b,0,2);
            }
        }
        p++;
    }
    return 0;
}

