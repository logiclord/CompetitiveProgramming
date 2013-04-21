#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    while(1)
    {
        vector<int> v;
        int current = 0;
        int timePassed = 180000;
        while(scanf("%d",&current)!=EOF && current!=0)
        {
            timePassed = min(timePassed, current);
            v.push_back(current);
        }
        if(v.size() == 0)
        {
            break;
        }

        while(timePassed <= 18000)
        {
            bool allGreen = true;
            for(vector<int>::iterator it= v.begin(); it!=v.end(); it++)
            {
                int exp = timePassed%(2*(*it));
                if(exp >= (*it-5))
                {
                    allGreen = false;
                    break;
                }
            }
            if(allGreen)
            {
                break;
            }
            timePassed++;
        }

        if(timePassed<=18000)
        {
            int hour = timePassed/3600;
            int minutes = timePassed/60 - hour*60;
            int seconds = timePassed%60;
            if(hour<=9)
                cout<<"0"<<hour<<":";
            else
                cout<<hour<<":";
            if(minutes<=9)
                cout<<"0"<<minutes<<":";
            else
                cout<<minutes<<":";
            if(seconds<=9)
                cout<<"0"<<seconds<<endl;
            else
                cout<<seconds<<endl;
        }
        else
        {
            printf("Signals fail to synchronise in 5 hours\n");
        }
    }
    return 0;
}



