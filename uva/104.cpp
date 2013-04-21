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
#include<cmath>
using namespace std;

double graph[21][21][21];
int parent[21][21][21];

int main()
{
    int n= 1;
    while(scanf("%d",&n)!=EOF && n)
    {
        memset(graph, 0.0, sizeof(graph));
        memset(parent, -1, sizeof(parent));

        for(int i=0; i<n; i++)
        {
            for(int j=0; j <n; j++)
            {
                if(i==j)
                {
                    graph[i][j][0] = 1.0;
                    continue;
                }
                cin>>graph[i][j][0];
            }
        }

        bool getout = false;
        for(int s=1; s<n && !getout; s++)
        {
            for(int k=0; k<n && !getout; k++)
            {
                for(int i=0; i<n && !getout; i++)
                {
                    for(int j=0; j < n && !getout; j++)
                    {
                        if(graph[i][j][s] < graph[i][k][s-1] * graph[k][j][0])
                        {
                            parent[i][j][s] = k;
                            graph[i][j][s] = graph[i][k][s-1] * graph[k][j][0];
                        }
                    }
                }
            }
        }

        vector<int> v;
        for(int s=0; s<n && !getout; s++)
        {
            for(int i=0;i<n && !getout;i++)
            if(graph[i][i][s] > 1.01)
            {
             //   cout<<"found "<<s<<" "<<graph[i][i][s]<<endl;
                getout = true;
                int tmp = parent[i][i][s];
                v.push_back(i+1);
                while(s>0)
                {
                    v.push_back(tmp+1);
                    s--;
                    tmp = parent[i][tmp][s];
                    //s--;
                }
                v.push_back(i+1);
            }
        }
        if(v.size()==0)
        {
            cout<<"no arbitrage sequence exists\n";
        }
        else
        {
            for(int k = v.size()-1; k>0; k--)
            {
                cout<<v[k]<<" ";
            }
            cout<<v[0]<<endl;
        }
        /*
                for(int i=0; i<n; i++)
                {
                    for(int j=0; j <n; j++)
                    {
                        cout<<graph[i][j][n-1]<<"\t";
                    }
                    cout<<endl;
                }
        */


    }
    return 0;
}


