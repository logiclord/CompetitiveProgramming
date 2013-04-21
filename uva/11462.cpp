#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include<cstring>
#include<cstdlib>

using namespace std;


int main()
{
    int t;
    while(scanf("%d",&t) && t!=0)
    {
        int cur;
        bool firstTime = true;
        int hash[101] = {0};
        while(t--)
        {
            scanf("%d",&cur);
            hash[cur]++;
        }
        for(int i=1; i<=100; i++)
        {
            while(hash[i]--)
            {
                if(firstTime)
                {
                    printf("%d",i);
                    firstTime = false;
                }
                else
                    printf(" %d",i);
            }
        }
        printf("\n");
    }
    return 0;
}
