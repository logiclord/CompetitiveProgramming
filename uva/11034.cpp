#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <sstream>
using namespace std;


int main()
{
    int p;
    scanf("%d",&p);
    while(p--)
    {
        int m,t, cur;
        char side[10];
        scanf("%d%d",&t,&m);
        int curentCoast = 0;
        queue<int> coasts[2];
        int totalIterations = 0;
        t = t * 100;
        for(int i=0; i<m; i++)
        {
            scanf("%d %s",&cur,side);
            if(side[0]=='l')
            {
                coasts[0].push(cur);
            }
            else if(side[0]=='r')
            {
                coasts[1].push(cur);
            }
        }

        curentCoast = 0;
        bool loaded = false;
        while(!coasts[0].empty() || !coasts[1].empty())
        {
           // cout<<coasts[0].size()<<" "<<coasts[1].size()<<endl;
            if(!coasts[0].empty())
            {
               // cout<<"--in1\n";
                int length = t;
                while(!coasts[0].empty() && (length-coasts[0].front())>0)
                {
                    //cout<<"shifting "<<coasts[0].front()<<endl;
                    length = length - coasts[0].front();
                    coasts[0].pop();
                    loaded = true;
                }
            }
            totalIterations++;
            loaded = false;
            if(!coasts[1].empty())
            {
                //cout<<"--in2\n";
                int length = t;
                while(!coasts[1].empty() && (length-coasts[1].front())>0)
                {
                   // cout<<"shifting "<<coasts[1].front()<<endl;
                    length = length - coasts[1].front();
                    coasts[1].pop();
                    loaded = true;
                }
            }
            if(loaded || !coasts[0].empty() || !coasts[1].empty())
            {
                totalIterations++;
            }
            loaded = false;
        }
        printf("%d\n",totalIterations);
    }
    return 0;
}
