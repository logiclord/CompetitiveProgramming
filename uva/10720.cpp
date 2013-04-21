#include <map>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int n;
    while(scanf("%d",&n) && n)
    {
        vector<int> v;
        long long dump[10009]= {0};
        long long su = 0;
        int cur;
        bool correct = false;
        for(int i=0; i<n; i++)
        {
            scanf("%d",&cur);
            v.push_back(cur);
            su += cur;
        }
        std::greater<int> gi;
        sort(v.begin(),v.end(),gi);

        if(su%2==0)
        {
            long long running = 0;
            for(int j=n-1; j>=0; j--)
            {
                //cout<<v[j]<<" ";
                running += v[j];
                dump[j] = running;
            }
            long long right = 0;
            correct = true;
            su = 0;
            for(int i=0; i<n; i++)
            {
                long long x= 0;
                for(int j=i+1;j<n;j++)
                {
                    x += min(i+1, v[j]);
                }
                su += v[i];
                right = i*(i+1) + x;
                if(su > right)
                {
                    correct = false;
                    break;
                }

            }
        }

        if(!correct)
        {
            printf("Not possible\n");
        }
        else
        {
            printf("Possible\n");
        }

    }
    return 0;
}

