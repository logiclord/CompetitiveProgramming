#include <map>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

int hash[200010];
int first[200010];
int last[200010];


int freq[100001];
int data[100001];
int segTree[1000000];

void buildTree(int i, int j, int vertex)
{
    //cout<<"--"<<i<<" "<<j<<endl;
    if(i==j)
    {
        segTree[vertex] = 1;
    }
    else
    {
        buildTree(i, (i+j)/2, 2*vertex);
        buildTree(((i+j)/2)+1,j, 2*vertex+1);
        if(data[j]==data[i])
        {
            segTree[vertex] =  j-i+1;
        }
        else
        {
            int x = min(j,last[data[i]+100000]) - i +1;
            int y = j - max(i,first[data[j]+100000])+1;
            int z = 0;
            int tmp = (i+j)/2;
            if(data[tmp] == data[tmp+1])
            {
                z = min(j,last[data[tmp]+100000]) - max(i,first[data[tmp]+100000])+1;
            }
            segTree[vertex] = max(max(x,y),max(max(segTree[ 2*vertex],segTree[ 2*vertex+1]),z));
        }
       // cout<<"--"<<i<<" "<<j<<" "<<segTree[vertex]<<endl;
    }
}

int query(int i,int j, int l, int r, int vertex)
{
    if(r<i || j<l)
    {
        return -1;
    }
    else if(i>=l && j<=r)
    {
        return segTree[vertex];
    }
    else
    {
        int p1 = query(i, (i+j)/2,l,r, 2*vertex );
        int p2 = query((i+j)/2+1, j,l,r, 2*vertex+1);

        int tmp = (i+j)/2, z = -1;
        if(data[tmp] == data[tmp+1])
        {
            z = min(min(j,r),last[data[tmp]+100000]) - max(max(i,l),first[data[tmp]+100000])+1;
        }

        return max(p1,max(p2,z));
    }
}


int main()
{
    int n,q;
    while(scanf("%d",&n)!=EOF && n)
    {
        scanf("%d",&q);
        memset(hash, 0,200001*sizeof(int));
        for(int i=0; i<n; i++)
        {
            scanf("%d",&data[i]);
            hash[data[i]+100000]++;
        }
        for(int i=0; i<n; i++)
        {
            freq[i] = hash[data[i] + 100000];
            if(i>0 && data[i]!=data[i-1])
            {
                first[data[i]+100000] = i;
            }
            if(i==n-1 || data[i]!=data[i+1])
            {
                last[data[i]+100000] = i;
            }
        }
        buildTree(0, n-1, 1);
        int t1,t2;

        for(int i=0; i<q; i++)
        {
            scanf("%d%d",&t1,&t2);
            printf("%d\n",query(0,n-1,t1-1,t2-1,1));
        }
    }
    return 0;
}

