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

int graph[101][101];
int parent[101][101];
map<string, int> hash;
map<int, string> revhash;


string printPath2(int i,int j)
{
    if(parent[i][j] == -1)
        return " ";
    else
        return (printPath2(i, parent[i][j]) + revhash[parent[i][j]] + printPath2(parent[i][j], j));
}
void printPath(int i,int j)
{
    if(i!=j)
        printPath(i, parent[i][j]);
    cout<<revhash[j]<<" ";
}

int main()
{
    int n= 1,t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        hash.clear();
        revhash.clear();
        memset(parent, -1, sizeof(parent));
        string str;

        for(int i=0; i<n; i++)
        {
            cin>>str;
            hash[str] = i;
            revhash[i] = str;
        }

        for(int i=0; i<n; i++)
        {
            for(int j=0; j <n; j++)
            {
                parent[i][j] = -1;
                cin>>graph[i][j];
            }
        }


        for(int k=0; k<n ; k++)
        {
            for(int i=0; i<n ; i++)
            {
                for(int j=0; j < n ; j++)
                {
                    if(graph[i][k]!=-1 && graph[k][j]!=-1 && (graph[i][j] ==-1 || graph[i][j] > graph[i][k] + graph[k][j]))
                    {
                        parent[i][j] = k ;//parent[k][j];
                        graph[i][j] = graph[i][k] + graph[k][j];
                    }
                }
            }
        }

/*
        for(int k=0; k<n ; k++)
        {
            for(int i=0; i<n ; i++)
            {
                cout<<parent[k][i]<<" ";
            }
            cout<<endl;
        }
*/

        int m;
        cin>>m;
        string sr,dt;
        for(int i=0; i<m; i++)
        {
            cin>>str>>sr>>dt;
            int x = hash[sr], y = hash[dt];
            if(graph[x][y] == -1)
            {
                cout<<"Sorry Mr "<<str<<" you can not go from "<<sr<<" to "<<dt<<endl;
            }
            else
            {
                cout<<"Mr "<<str<<" to go from "<<sr<<" to "<<dt<<", you will receive "<<graph[x][y]<<" euros\n";
                cout<<"Path:";
                cout<<revhash[x]<<printPath2(x,y)<<revhash[y]<<endl;
               // printPath(x,parent[x][y]);
               // cout<<revhash[y]<<endl;
            }
        }
    }
    return 0;
}


