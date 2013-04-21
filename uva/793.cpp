#include <map>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;


int prep[1000000];

int findSet(int x)
{
  //  cout<<"@@"<<x<<endl;
    if(prep[x]==x)
        return x;
    return (prep[x] = findSet(prep[x]));
}
bool isSameSet(int x, int y)
{
    return (findSet(x) == findSet(y));
}

void unionSet(int x, int y)
{
    prep[findSet(x)] = findSet(y);
}

void initialDD(int n)
{
    for(int i=0; i<=n; i++)
    {
        prep[i] = i;
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    bool blank = false;
    while(t--)
    {
        if(blank)
            printf("\n");
        blank = true;
        int n,x,y,n1=0,n2=0;
        char p;
        scanf("%d",&n);
        initialDD(n);
        char line[100];
        getchar();
        while(gets(line) && strlen(line))
        {
            sscanf(line,"%c%d%d",&p,&x,&y);
            //cout<<"--"<<p<<x<<y<<endl;
            if(p == 'c')
                unionSet(x,y);
            else if(p=='q')
            {
                if(isSameSet(x,y))
                {
                    n1++;
                }
                else
                {
                    n2++;
                }
            }
        }
        printf("%d,%d\n",n1,n2);
    }
    return 0;
}

