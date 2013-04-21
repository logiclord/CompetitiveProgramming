#include <iostream>
#include <cstring>
#include <algorithm>
#include <limits.h>
#include<cstdio>
#include<map>
using namespace std;

int mini = 0;
int raw[10];

bool validate(int data[], int num)
{
    bool ret = true;

    for(int i=0; ret && i<=num; i++)
    {
        for(int j=i+1; ret && j<=num; j++)
        {
            if(data[i]==data[j] || abs(data[i]-data[j]) == abs(i-j))
            {
                ret = false;
            }
        }
    }

    return ret;
}

void move (int data[8], int n)
{
    if(n==8)
    {
        int diff = 0;
        for(int k=0; k<8; k++)
        {
            diff += (raw[k]!=data[k]);
        }
        mini = min(diff,mini);
        //cout<<data[0]<<" "<<data[1]<<" "<<data[2]<<" "<<data[3]<<" "<<data[4]<<" "<<data[5]<<" "<<data[6]<<" "<<data[7]<<endl;
    }
    else
    {
        for(int i=1; i<=8; i++)
        {
            data[n] = i;
            if(validate(data,n))
            {
                move(data, n+1);
            }
        }
    }
}

int main()
{
    int data[8], p=1;
    while(scanf("%d%d%d%d%d%d%d%d",&data[0],&data[1],&data[2],&data[3],&data[4],&data[5],&data[6],&data[7])!=EOF)
    {
        for(int k=0; k<8; k++)
        {
            raw[k] = data[k];
        }
        mini = 99999;
        move(data,0);
        printf("Case %d: %d\n",p,mini);
        p++;
    }
    return 0;
}
