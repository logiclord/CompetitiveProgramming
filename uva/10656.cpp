#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    while(scanf("%d",&n) && n)
    {
        vector<int> v;
        int t;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&t);
            if(t>0)
            {
                v.push_back(t);
            }
        }
        if(v.size()==0)
        {
            printf("0\n");
        }
        else
        {
            vector<int>::iterator it =v.begin();
            printf("%d",*it);
            it++;
            for(;it!=v.end();it++)
            {
                printf(" %d",*it);
            }
            printf("\n");
        }
    }
    return 0;
}
