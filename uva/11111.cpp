#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <stack>
#include <sstream>
using namespace std;


int main()
{
    string l;
    while (getline(cin, l))
    {
        stack<pair<int, long long> > s;
        bool isValid = true;
        istringstream iss(l);
        int cur;
        while(iss>>cur)
        {
            //cout<<s.size()<<" "<<cur<<" "<<endl;
            if(cur < 0)
            {
                if(!s.empty())
                    s.top().second += (cur*-1);
                s.push(make_pair(cur*-1,0));
            }
            else if(cur > 0 && s.empty())
            {
                isValid = false;
                break;
            }
            else
            {
                pair<int,long long> tp = s.top();
                s.pop();
               // cout<<"--"<<tp.first<<" "<<tp.second<< " "<<cur<<"\n";
                if(tp.first != cur || tp.first<=tp.second)
                {
                    isValid = false;
                    break;
                }
               // cout<<"$$$$\n";
            }
        }
        if(!s.empty())
        {
            isValid = false;
        }
        if(isValid)
        {
            printf(":-) Matrioshka!\n");
        }
        else
        {
            printf(":-( Try again.\n");
        }
    }
    return 0;
}





