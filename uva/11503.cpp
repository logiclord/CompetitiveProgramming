#include <map>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;


int prep[1000000];
int members[1000000];

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

int unionSet(int x, int y)
{
    if(isSameSet(x,y))
    {
        return members[findSet(y)];
    }
    members[findSet(y)] += members[findSet(x)];
    prep[findSet(x)] = findSet(y);
   // cout<<"-"<<members[prep[y]]<<" "<<x<<endl;
   // cout<<"!"<<members[prep[x]]<<" "<<y<<endl;

    return members[findSet(y)];
}

void initialDD(int n)
{
    for(int i=0; i<=n; i++)
    {
        prep[i] = i;
        members[i] = 1;
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    bool blank = false;
    while(t--)
    {
    //    if(blank)
    //        printf("\n");
    //    blank = true;
        int n,x,y,n1=0,n2=0;
        char p;
        scanf("%d",&n);
        initialDD(n);
        string str1,str2;
        map<string, int> hash;
        int index = 0;
        while(n--)
        {
            cin>>str1>>str2;
            if(hash.find(str1) == hash.end())
            {
                hash[str1] = index;
                index++;
            }
            if(hash.find(str2) == hash.end())
            {
                hash[str2] = index;
                index++;
            }
            //cout<<"--"<<p<<x<<y<<endl;
            printf("%d\n",unionSet(hash[str1],hash[str2]));
        }

    }
    return 0;
}

