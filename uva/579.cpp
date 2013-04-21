#include <cstdio>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <set>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    int h,m;
    char c;
    scanf("%d%c%d",&h,&c,&m);
    while(!(h==0 && m==0))
    {
        float angle = abs(30*h - (11*m)/2.0);
        if(angle > 180 )
        {
            angle = 360 - angle;
        }
        printf("%.3f\n",angle);
    scanf("%d%c%d",&h,&c,&m);
    }
    return 0;
}
