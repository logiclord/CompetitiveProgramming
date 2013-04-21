#include <iostream>
#include <cstring>
#include <algorithm>
#include <limits.h>
#include<cstdio>
#include<map>
using namespace std;

int mini = 0;
bool hash[20][20];
int rows;
int power2[35000] = {0};
int data[20];
bool diagonal[100];
bool diagonal2[100];

bool validate(int num)
{
    bool ret = true;
    for(int i=0; i<num; i++)
    {
        if(abs(data[i]-data[num]) == abs(i-num))
        {
            ret = false;
            break;
        }
    }
    return ret;
}

void queen(int n,int m)
{
    if(n==m)
    {
        mini++;
        //cout<<"Got one more "<<mini<<endl;
    }
    else
    {
        int tmp2 = rows;
        //for(int i=0; i<m; i++)
        while(tmp2)
        {
            int tmp = tmp2&(-tmp2);
            int i = power2[tmp];
            if(!diagonal[i-n+20] && !diagonal2[i+n] && hash[i][n] == false)
            {
                data[n] = i;
                diagonal[i-n+20] = true;
                diagonal2[i+n] = true;
                rows = rows & (~tmp);
                queen(n+1,m);
                rows = rows | tmp;
                diagonal[i-n+20] = false;
                diagonal2[i+n] = false;
            }
            tmp2 = tmp2 & (~tmp);
        }
    }
}

int main()
{
    int  p=1, m;
    char tmp;
    power2[1] = 0;
    power2[2] = 1;
    power2[4] = 2;
    power2[8] = 3;
    power2[16] = 4;
    power2[32] = 5;
    power2[64] = 6;
    power2[128] = 7;
    power2[256] = 8;
    power2[512] = 9;
    power2[1024] = 10;
    power2[2048] = 11;
    power2[4096] = 12;
    power2[8192] = 13;
    power2[16384] = 14;
    power2[32768] = 14;

    while(scanf("%d",&m) && m)
    {
        rows = ((1<<m) - 1);

        for(int i=0; i<50; i++)
        {
            diagonal[i] = false;
            diagonal2[i] = false;
        }

        for(int i=0; i<m; i++)
        {
            getchar();
            for(int j=0; j<m; j++)
            {
                hash[i][j] = false;
                tmp = getchar();
                if(tmp == '*')
                {
                    hash[i][j] = true;
                }
            }
        }
        mini = 0;

        queen(0,m);
        printf("Case %d: %d\n",p,mini);
        p++;
    }
    return 0;
}
