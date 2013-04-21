#include <map>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;

bool isComp(string str)
{
    return (str.compare("<")==0 || str.compare(">")==0 || str.compare("=")==0 || str.compare("<=")==0 || str.compare(">=")==0);
}
int main()
{
    map<string, int> hash;
    int p,g;
    scanf("%d%d",&p,&g);
    while(p--)
    {
        double score;
        string tmp;
        cin>>tmp>>score;
        hash[tmp] = score*10;
    }
    for(int i=1; i<=g; i++)
    {
        bool completed = false;
        string cur;
        int total = 0;
        while(1)
        {
            cin>>cur;
            if(cur[0] == '+')
            {
                continue;
            }
            else if(!isComp(cur))
            {
                total += hash[cur];
            }
            else
            {
                int n;
                cin>>n;
                n = n * 10;
                if(cur.compare("<")==0 && total < n)
                {
                    completed = true;
                }
                else if(cur.compare(">")==0 && total > n)
                {
                    completed = true;
                }
                else if(cur.compare("=")==0 && (total==n))
                {
                    completed = true;
                }
                else if(cur.compare("<=")==0 && (total <= n))
                {
                    completed = true;
                }
                else if(cur.compare(">=")==0 && (total >= n))
                {
                    completed = true;
                }
                break;
            }
        }
        if(!completed)
            printf("Guess #%d was incorrect.\n",i);
        else
            printf("Guess #%d was correct.\n",i);
    }
    return 0;
}

