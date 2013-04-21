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



int main()
{
    int n = 1;
    int t = 1;

    while(cin>>n && n)
    {
        string cur = "", next= "";
        bool graph[101][101] = {false};
        map<string, int> hash;
        map<int, string> hash2;
        int counter = 0;

        for(int i=0; i<n; i++)
        {
            int p;
            cin>>p;
            cur = "";
            next = "";
            for(int j=0; j<p; j++)
            {
                cin>>next;
                hash2[counter] = next;
                hash[next] = counter;
                counter++;
                if(cur != "")
                {
                    graph[hash[cur]][hash[next]] = true;
                    //   graph[hash[next]][hash[cur]] = true;
                }
                cur = next;
            }
        }
        int m;
        cin>>m;
        for(int i=0; i<m; i++)
        {
            cin>>cur>>next;
            graph[hash[cur]][hash[next]] = true;
            //  graph[hash[next]][hash[cur]] = true;
        }

        /*
                for(int k=0; k<counter; k++)
                {
                    for(int i=0; i<counter; i++)
                    {
                        cout<<graph[k][i]<<" ";
                    }
                    cout<<endl;
                }
         */

        for(int k=0; k<counter; k++)
        {
            for(int i=0; i<counter; i++)
            {
                for(int j=0; j<counter; j++)
                {
                    graph[i][j] = graph[i][j] || (graph[i][k] && graph[k][j]);
                }
            }
        }
        vector<pair<int,int> >v;

        /*
                for(int k=0; k<counter; k++)
                {
                    for(int i=0; i<counter; i++)
                    {
                        cout<<graph[k][i]<<" ";
                    }
                    cout<<endl;
                }
        */
        for(int k=0; k<counter ; k++)
        {
            for(int i=k+1; i<counter; i++)
            {
                if(i!=k && !graph[k][i] && !graph[i][k])
                {
                    v.push_back(make_pair(k,i));
                }
            }
        }
        if(v.size() == 0)
        {
            printf("Case %d, no concurrent events.\n",t);
        }
        else
        {
            int k = v.size();
            printf("Case %d, %d concurrent events:\n",t,k);
            vector<pair<int,int> >::iterator it= v.begin();
            cout<<"("<<hash2[it->first]<<","<<hash2[it->second]<<")";
            it++;
            if(it!=v.end())
            {
                cout<<" ("<<hash2[it->first]<<","<<hash2[it->second]<<")";
            }
            cout<<endl;
        }

        t++;
    }
    return 0;
}


