#include <cstdio>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <set>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <deque>
#include <map>
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int ss,dd,a,b;
        //cin>>ss>>dd;
        scanf("%d%d",&ss,&dd);
        //cout<<a<<b;
        a = (ss+dd) /2;
        b = (ss-dd)/2;
       //   cout<<a<<b;
       // printf("%d %d\n",a,b);
        if(a<0 || b < 0 || a+b!=ss || a-b!=dd)
        {
            printf("impossible\n");
        }
        else
        {
            printf("%d %d\n",a,b);
        }
    }
    return 0;
}





