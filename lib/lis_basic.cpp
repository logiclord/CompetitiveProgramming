#include<cstdio>
#include<vector>
#include<climits>
#include<algorithm>
#include<cstring>
#include<cctype>
#include<iostream>

using namespace std;

int parent[100000];
int lis[100000];
int lastLen[100000];

int main()
{
    int tmp, index = 0;
    vector<int> v;

    while(scanf("%d",&tmp)!=EOF)
    {
      //  cout<<"-"<<tmp<<endl;
        v.push_back(tmp);
        parent[index] = -1;
        lis[index] = 0;
        lastLen[index] = -1;
        index++;
    }

    int lisMax = INT_MIN;
    int lisIndex;

    parent[0] = -1;
    lis[0] = 1;
    for(int i=1; i<index; i++)
    {
        int  mii = -1, lislen = 1;
        for(int k=i-1; k>=0; k--)
        {
            if(v[k]<v[i] && lislen<lis[k]+1)
            {
              //  cout<<"extending "<<i<<" "<<k<<" ";
              // cout<<mii<<" "<<lislen<<endl;
                mii = k;
                lislen = lis[k] + 1;
            }
        }
       // cout<<mii<<" "<<lislen<<endl;
        parent[i] = mii;
        lis[i] = lislen ;
        if(lis[i]>=lisMax)
        {
            lisMax = lis[i];
            lisIndex = i;
        }
    }
    cout<<lisMax<<"\n-\n";
    int temp[100000];
    int i,j;
    for( i=0, j=lisIndex;j>=0 ;i++,j=parent[j])
    {
        temp[i] = v[j];
    }

    while(i--)
    {
        printf("%d\n",temp[i]);
    }

    return 0;
}
