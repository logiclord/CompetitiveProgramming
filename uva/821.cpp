#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <set>
#include <vector>
#include<map>
#include<cstdio>
#include<stack>
#include<cstring>
#include<climits>
using namespace std;

int main()
{
    int n, m, testcase = 1;
    int t = 1;
    while(scanf("%d%d",&n,&m) && (n|m))
    {
        set<int> st;
        int graph[101][101];
        for(int i=1; i<=100; i++)
        {
            for(int j=1; j <=100; j++)
            {
                graph[i][j] = 10000000;
            }
        }

        graph[n][m] = 1;
        while(scanf("%d%d",&n,&m) && (n|m))
        {
            st.insert(n);
            st.insert(m);
            graph[n][m] = 1;
        }

        int count = *st.rbegin();
        for(int k=1; k<=count; k++)
        {
            for(int i=1; i<=count; i++)
            {
                for(int j=1; j <=count; j++)
                {
                        graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                }
            }
        }

        int sum = 0;
        for(int i=1; i<=count; i++)
        {
            for(int j=1; j <=count; j++)
            {
               // cout<<graph[i][j]<<" ";
                if(i != j && graph[i][j]!=10000000)
                    sum += graph[i][j];
            }
           // cout<<endl;
        }

        int pr = (st.size()*(st.size()-1));
        printf("Case %d: average length between pages = %.3lf clicks\n",t,(double)sum/pr);
        t++;
    }
    return 0;
}
