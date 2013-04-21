#include<iostream>
#include<list>
#include<string>
#include<cstring>
#include<sstream>
#include<cctype>
#include<string.h>
#include<algorithm>
#include<cmath>
#include<stack>
#include<fstream>
#include<cstdlib>
#include<vector>
#include<map>
#include<set>
#include<utility>
#include<iomanip>
#include<queue>

using namespace std;

int main()
{
    map<int,int>mp;
    int k,p,m,dead,newp;
    while ((cin>>k)&&k)
    {
        if(mp[k])
        {
            cout<<mp[k]<<endl;
            continue;
        }
        p = k*2;
        for(m=k; ;m++)
            {
                newp=p;
                dead=(m-1)%newp;
                while (dead>=k && newp>=k)
                {
                    newp--;
                    dead = (dead-1+m)%newp;
                }
                if (newp==k)
                    {
                        mp[k]=m;
                        break;
                    }
            }
            cout << m << endl;
        }
    }