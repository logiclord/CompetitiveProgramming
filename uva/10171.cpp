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
    int t = 1;
    while(scanf("%d",&t) && t)
    {
        int graph1[101][101];
        int graph2[101][101];

        for(int i=0; i<101; i++)
        {
            for(int j=0; j <101; j++)
            {
                graph1[i][j] = 10000000;
                graph2[i][j] = 10000000;
            }
            graph1[i][i] = 0;
            graph2[i][i] = 0;
        }

        char a,dir,s,d;
        int en;
        for(int i=0; i<t; i++)
        {
            getchar();
            scanf("%c %c %c %c %d",&a,&dir,&s,&d,&en);
            //cout<<a<<" "<<dir<<" "<<s<<" "<<d<<endl;
            if(a == 'Y')
            {
                graph1[s][d] = min(graph1[s][d],en);
                if(dir == 'B')
                {
                    graph1[d][s] = min(graph1[d][s],en);
                }
            }
            else
            {
                graph2[s][d] = min(graph2[s][d],en);
                if(dir == 'B')
                {
                    graph2[d][s] = min(graph2[d][s],en);
                }
            }
        }

        for(int k='A'; k<='Z'; k++)
        {
            for(int i='A'; i<='Z'; i++)
            {
                for(int j='A'; j <='Z'; j++)
                {
                    if(graph1[i][j] > graph1[i][k] + graph1[k][j])
                    {
                        graph1[i][j] = graph1[i][k] + graph1[k][j];
                    }
                    if(graph2[i][j] > graph2[i][k] + graph2[k][j])
                    {
                        graph2[i][j] = graph2[i][k] + graph2[k][j];
                    }
                }
            }
        }

        getchar();
        scanf("%c %c",&s,&d);

        //Can be solved with 2 dikshtra
        int cost = graph1[s]['A'] + graph2[d]['A'];
        for(int i='B'; i<='Z'; i++)
        {
            cost = min(cost, graph1[s][i] + graph2[d][i]);
        }
        if(cost >= 10000000)
        {
            cout<<"You will never meet.\n";
        }
        else
        {
            cout<<cost;
            for(int i='A'; i<='Z'; i++)
            {
                if(cost == graph1[s][i] + graph2[d][i])
                {
                    printf(" %c",(char)i);
                }
            }
            printf("\n");
        }
    }
    return 0;
}


