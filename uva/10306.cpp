#include<cstdio>
#include<vector>
#include<climits>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cctype>
#include<iostream>

using namespace std;

int data[100000];

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n, m, tmp;
        vector<int> v;
        scanf("%d%d",&n,&m);
        for(int i=0; i<m; i++)
        {
            scanf("%d",&tmp);
            v.push_back(tmp);
        }
        for(int i=0; i<100000; i++)
        {
            data[i] = INT_MAX;
        }
        data[0] = 0;
        for(vector<int>::iterator it = v.begin(); it!=v.end(); it++)
        {
            for(int i=30001; i>=0; i--)
            {
               //cout<<i<<" "<<data[i]<<endl;
                if(data[i]!=INT_MAX)
                {
                    //   cout<<"    ^^^^^ "<<i+ *it<<" "<<data[i+ *it]<<endl;
                    data[i+ *it] = min(data[i+ *it], data[i]+1);
                }
            }
        }
        int i;
        for(i=n; data[i]==INT_MAX; i++)
        {
            // cout<<i<<" "<<data[i]<<endl;
        }

        printf("%d %d\n", i, data[i]);
    }
    return 0;
}



