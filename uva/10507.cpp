#include <map>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

map<char, int> hashing;
int counting = 0;
int getNum(int c)
{
    if(hashing.find(c)==hashing.end())
    {
        hashing[c] = counting;
        counting++;
    }
    return hashing[c];
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        hashing.clear();
        counting = 0;
        int c;
        char tmp,tmp2;
        scanf("%d",&c);
        bool graph[26][26] = {false};
        bool awake[26] = {false};
        getchar();
        for(int i=0; i<3; i++)
        {
            scanf("%c",&tmp);
            awake[getNum(tmp)] = true;
            //cout<<"-@-"<<getNum(tmp)<<endl;
        }
        for(int i=0; i<c; i++)
        {
            getchar();
            scanf("%c%c",&tmp,&tmp2);
            graph[getNum(tmp)][getNum(tmp2)] = true;
            graph[getNum(tmp2)][getNum(tmp)] = true;
            //cout<<"--"<<getNum(tmp)<<" "<<getNum(tmp2)<<endl;
        }
        int years = 0;
        while(1)
        {
            vector<int> v;
            for(int i=0; i<n; i++)
            {
                // cout<<"$ "<<i<<"\n";
                int awakeNeighbours = 0;
                for(int j=0; !awake[i] && j<n; j++)
                {
                    if(graph[i][j])
                    {
                        //cout<<j<<" "<<endl;
                        if(awake[j])
                        {
                            awakeNeighbours++;
                            //cout<<"\\m/\n";
                        }
                    }
                }
                if(awakeNeighbours>=3)
                {
                    v.push_back(i);
                }
            }
            years++;
            for(vector<int>::iterator it = v.begin(); it!=v.end(); it++)
            {
               // cout<<*it<<" ";
                awake[*it] = true;
            }
            if(v.size() == 0)
                break;
        }

        bool allAwake = true;
        for(int j=0; j<n; j++)
        {
            allAwake = allAwake & awake[j];
        }


        if(allAwake)
            printf("WAKE UP IN, %d, YEARS\n",years-1);
        else
            printf("THIS BRAIN NEVER WAKES UP\n");
    }
    return 0;
}

