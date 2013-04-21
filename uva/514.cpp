#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <stack>

using namespace std;

int main()
{
    int t;
    while(scanf("%d",&t) && t)
    {
        int tmp;
        while(scanf("%d",&tmp) && tmp)
        {
            vector<int> v;
            v.push_back(tmp);
            for(int i=1; i<t; i++)
            {
                scanf("%d",&tmp);
                v.push_back(tmp);
            }
            int y=1,j=0;
            bool possible = true;
            stack<int> s;
/*
            for(int i=0; i<t; i++)
            {
                printf("%d\n",v[i]);
            }
            cout<<endl;
*/
            while(!s.empty() || y<=t)
            {
                //cout<<"--size:"<<s.size()<<" "<<v[j]<<" "<<y<<endl;
                if(y==v[j])
                {
                    y++;
                    j++;
                }
                else if(!s.empty() && v[j]==s.top())
                {
                    s.pop();
                    j++;
                }
                else if(y<=t && y!=v[j])
                {
                    s.push(y);
                    y++;
                }
                else
                {
                    possible = false;
                    break;
                }
            }
          //  cout<<possible<<"--\n";
            if(possible)
            {
                printf("Yes\n");
            }
            else
            {
                printf("No\n");
            }
        }
        printf("\n");
    }

    return 0;
}
