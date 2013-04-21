#include <map>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    getchar();
    getchar();
    bool blank = false;
    while(cases--)
    {
        map<string,int> m;
        string in;
        int total = 0;
        while(getline(cin,in) && !in.empty())
        {
            m[in]++;
            total++;
        }
        if(blank)
            printf("\n");
        blank = true;
        for(map<string,int>::iterator it = m.begin() ; it!= m.end(); it++)
        {
            printf("%s %.4lf\n",it->first.c_str(),it->second*100.00/total);
        }
    }
}
