#include <iostream>
#include <cstring>
#include <algorithm>
#include <limits.h>
#include<cstdio>
#include<map>
using namespace std;

int bitsSet(int n)
{
    int count = 0;
    while(n)
    {
        n = n&(n-1);
        count++;
    }
    return count;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int p,n,tmp;
        int data[101];
        scanf("%d%d",&p,&n);
        for(int i=0; i<n; i++)
        {
            int current = 0;
            for(int j=0; j<p; j++)
            {
                scanf("%d",&tmp);
                current = current*2 + tmp;
            }
           data[i] = current;
        }
        int upperLimit = (1<<p);
        int maxi = 0;
        for(int i=1; i<upperLimit; i++)
        {
            bool valid = true;
            map<int,bool> hash;
            for(int j=0;j<n;j++)
            {
                int cur = data[j] & (~i);
                if(hash.find(cur) != hash.end())
                {
                    valid = false;
                    break;
                }
                hash[cur] = true;
            }
            if(valid)
            {
                maxi = max(maxi, bitsSet(i));
                //cout<<i<<"\n";
            }
        }
        cout<<p-maxi<<endl;
    }
    return 0;
}
