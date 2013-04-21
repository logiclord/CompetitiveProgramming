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

int month[] = {31,28,31,30,31,30,31,31,30,31,30,31};

int currentYearDays(int y)
{
    if(y%400 == 0)
        return 366;
    else if(y%100 != 0 && y%4==0)
        return 366;
    return 365;
}

int daysPassed(int m, int y, int d)
{
    int passed = 0;
    int cur = currentYearDays(y);
    for(int i=0; i<m-1; i++)
    {
        if(i==1 && y==366)
        {
            passed += 29;
        }
        else
        {
            passed += month[i];
        }
    }
    return passed+d;
}

int main()
{
    int dd,mm,y, n;
    scanf("%d%d%d%d",&n,&dd,&mm,&y);

    while(!(n == 0 && y == 0 && dd == 0 && mm == 0))
    {
        int currentMax = currentYearDays(y);
        int currentDays = daysPassed(mm,y,dd);
        int leftDays = currentMax - currentDays;
        if(leftDays < n)
        {
            n = n - leftDays;
            dd = 1;
            mm = 1;
            y++;
            currentMax = currentYearDays(y);
            while(currentMax < n)
            {
                y++;
                n = n - currentMax;
                currentMax = currentYearDays(y);
            }
        }
        else
        {
            n = n + dd;
        }
        bool isLeap = y%400==0 || (y%100 != 0 && y%4==0);
        for(int i = mm-1; i<12; i++)
        {
            int val = ((isLeap && i==1 )? 29 : month[i]);
            if(val >= n)
            {
                mm = i+1;
                dd = n;
                break;
            }
            n = n - val;
        }
        cout<<dd<<" "<<mm<<" "<<y<<endl;

        scanf("%d%d%d%d",&n,&dd,&mm,&y);
    }
    return 0;
}





