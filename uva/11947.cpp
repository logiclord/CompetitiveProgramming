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


void zodiac(int m, int d)
{
    if((m == 1 && d >= 21) || (m == 2 && d <= 19)) puts("aquarius");
    else if((m == 2 && d >= 20) || (m == 3 && d <= 20)) puts("pisces");
    else if((m == 3 && d >= 21) || (m == 4 && d <= 20)) puts("aries");
    else if((m == 4 && d >= 21) || (m == 5 && d <= 21)) puts("taurus");
    else if((m == 5 && d >= 22) || (m == 6 && d <= 21)) puts("gemini");
    else if((m == 6 && d >= 22) || (m == 7 && d <= 22)) puts("cancer");
    else if((m == 7 && d >= 23) || (m == 8 && d <= 21)) puts("leo");
    else if((m == 8 && d >= 22) || (m == 9 && d <= 23)) puts("virgo");
    else if((m == 9 && d >= 24) || (m == 10 && d <= 23)) puts("libra");
    else if((m == 10 && d >= 24) || (m == 11 && d <= 22)) puts("scorpio");
    else if((m == 11 && d >= 23) || (m == 12 && d <= 22)) puts("sagittarius");
    else if((m == 12 && d >= 23) || (m == 1 && d <= 20)) puts("capricorn");
}

int daysPassed(int m, int y, int d)
{
    int passed = 0;
    int cur = currentYearDays(y);
   // cout<<cur<<endl;
    for(int i=0; i<m-1; i++)
    {
        if(i==1 && cur==366)
        {
            //cout<<"EEE\n";
            passed += 29;
        }
        else
        {
             //cout<<"fff\n";
            passed += month[i];
        }
              //  cout<<i<<" p : "<<passed<<endl;
    }
    return passed+d;
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int k=1; k<=t; k++)
    {
        //char date[9];
        //scanf("%s",date);
        int y,mm,dd;
        scanf("%2d%2d%4d",&mm,&dd,&y);
       // cout<<y<<mm<<dd<<endl;
        int n = 40*7;
        int currentMax = currentYearDays(y);
        int currentDays = daysPassed(mm,y,dd);
        //cout<<currentDays<<endl;
        int leftDays = currentMax - currentDays;
       // cout<<leftDays<<endl;
        if(leftDays < n)
        {
           // cout<<"1\n";
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
           // cout<<"2\n";
            n = n + dd;
        }
        //cout<<n<<endl;
        bool isLeap = y%400==0 || (y%100 != 0 && y%4==0);
        for(int i = mm-1; i<12; i++)
        {
            int val = ((isLeap && i==1 )? 29 : month[i]);
          //  cout<<i<<" "<<val<<endl;
            if(val >= n)
            {
                mm = i+1;
                dd = n;
                break;
            }
            n = n - val;
        }

        printf ("%d %02d/%02d/%04d ", k, mm, dd, y % 10000);;
        zodiac(mm,dd);//<<endl;
    }
    return 0;
}





