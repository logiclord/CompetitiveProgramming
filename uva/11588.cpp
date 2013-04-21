#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    for(int n=1;n<=t;n++)
    {
        long long val = 0;
        int maxi = 0;
        char grid[20][20] = {0};
        int hash[26] = {0};
        int m,k,r,c;
        scanf("%d%d%d%d",&r,&c,&m,&k);
       // getchar();
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                cin>>grid[i][j];// = getchar();
                maxi = max(++hash[grid[i][j] - 'A'], maxi);
            }
            //getchar();
        }
        /*
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                printf("%c-",grid[i][j]);
            }
            cout<<endl;
        }*/
        for(int i=0;i<26;i++)
        {
            //cout<<(char)(i+'A')<<" "<<hash[i]<<endl;
            if(hash[i] == maxi)
            {
                val += hash[i]*m;
            }
            else
            {
                val += hash[i]*k;
            }
        }

        printf("Case %d: %lld\n",n,val);
    }
    return 0;
}
