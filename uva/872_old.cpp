#include<cstdio>
#include<vector>
#include<climits>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cctype>
#include<iostream>
#include<cstdlib>
#include<map>
#include<set>

using namespace std;

map<char, vector<char> > graph;
set<pair<char,char> > pairHash;
string seed = "";
int dfs_state[1000];
int inStack[1000];
int fail = false;
vector<string> tp_sorts;

void dfs(char origin)
{
    dfs_state[origin] = 1;
    inStack[origin] = 1;
    for(vector<char>::iterator ip = graph[origin].begin(); ip!= graph[origin].end(); ip++)
    {
        if(inStack[*ip] == 1)
        {
            fail = true;
            return;
        }
        else if(dfs_state[*ip] == -1)
        {
            dfs(*ip);
        }
    }
    inStack[origin] = -1;
    seed.push_back(origin);
}

void generateAll(string cur, int index, int num)
{
    if(index == num)
    {
        tp_sorts.push_back(cur);
    }
    else
    {
        generateAll(cur, index+1, num);
        // Swapping all nodes without any dependency
        if(index<num-1 && pairHash.find(make_pair(cur[index],cur[index+1]))==pairHash.end())
        {
            swap(cur[index],cur[index+1]);
            generateAll(cur, index+1, num);
            swap(cur[index],cur[index+1]);
        }
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int cas=1; cas<=t; cas++)
    {
        graph.clear();
        pairHash.clear();
        seed = "";
        tp_sorts.clear();
        memset(inStack, -1, sizeof(inStack));
        memset(dfs_state, -1, sizeof(dfs_state));

        char tmp, tmp2;
        getchar();
        getchar();
        // getting source vertex
        while(scanf("%c",&tmp) && tmp!='\n')
        {
            if(tmp!=' ')
            {
                dfs_state[tmp] = -1;
                vector<char> v;
                graph.insert(make_pair(tmp,v));
            }
        }

        // getting dependencies
        while(scanf("%c",&tmp)!=EOF && tmp!='\n')
        {
            if(tmp != ' ')
            {
                scanf("<%c",&tmp2);
                //  cout<<tmp<<" "<<tmp2<<endl;
                pairHash.insert(make_pair(tmp,tmp2));
                graph[tmp].push_back(tmp2);
            }
        }
        /*
                for(map<char, vector<char> >::iterator it = graph.begin(); it!= graph.end(); it++)
                {
                    cout<<"Starting "<<it->first<<" -- ";
                    for(vector<char>::iterator ip = it->second.begin(); ip!= it->second.end(); ip++)
                    {
                        cout<<*ip<<"\t";
                    }
                    cout<<"\n";
                }
        */
        for(map<char, vector<char> >::iterator it = graph.begin(); it!= graph.end(); it++)
        {
            if(dfs_state[it->first]==-1)
            {
                dfs(it->first);
            }
        }
        if(fail == false)
        {
            seed.assign(seed.rbegin(), seed.rend());
            generateAll(seed,0, graph.size());
            sort(tp_sorts.begin(), tp_sorts.end());

            for(vector<string>::iterator it = tp_sorts.begin(); it!=tp_sorts.end(); it++)
            {
                // cout<<*it<<endl;
                string::iterator st = it->begin();
                printf("%c",*st);
                st++;
                for(; st!= it->end(); st++)
                {
                    printf(" %c",*st);
                }
                printf("\n");
            }
        }
        else
        {
            cout<<"NO\n";
        }

        if(cas!=t)
            printf("\n");
    }
}
