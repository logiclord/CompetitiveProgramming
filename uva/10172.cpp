#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;


int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        queue<int> qes[101];
        stack<int> s;
        int n,b,c, tmp, total = 0, tmp2,totalTime = 0;
        scanf("%d%d%d",&n,&c,&b);
        for(int i=0; i<n; i++)
        {
            scanf("%d",&tmp);
            total += tmp;
            while(tmp--)
            {
                scanf("%d",&tmp2);
                qes[i].push(tmp2);
            }
        }
        int k =0;
        int cur = 0;
        while(total>0)
        {
            k++;
            //if(k==5) break;

            //cout<<"--"<<cur<<" "<<total<<" "<<totalTime<<" "<<s.size()<<"\n";
            while(!s.empty() && (qes[cur].size()<b || s.top()==cur+1))
            {
                totalTime++;
                tmp = s.top();
                s.pop();
               // cout<<"--"<<tmp;
                if(tmp == cur+1)
                {
                   // cout<<"--matched\n";
                    total--;
                }
                else
                {
                  //  cout<<"--pushed\n";
                    qes[cur].push(tmp);
                }
            }
           // cout<<"%%\n";
            while(s.size()<c && !qes[cur].empty())
            {
                tmp = qes[cur].front();
                qes[cur].pop();
               // cout<<"@-"<<tmp<<endl;
                s.push(tmp);
                totalTime++;
            }
            if(total)
                totalTime += 2;
            cur = (cur + 1)%n;
            //if(total==9)break;
        }
        printf("%d\n",totalTime);
    }
    return 0;
}
