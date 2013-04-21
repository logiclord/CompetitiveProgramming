#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include<cstring>
using namespace std;



int main()
{
    int p;
    scanf("%d\n",&p);
    while(p--)
    {
        int mapping[1000] = {0};
        int t;
        unsigned char in;
        int val;
        scanf("%d\n",&t);

        while(t--)
        {
            //cout<<"--"<<t<<endl;
            scanf("%c %d\n",&in,&val);
            //cout<<"#"<<in<<"\t"<<val<<endl;
            mapping[in + 128] = val;
            // cout<<mapping[in]<<endl;
        }
        scanf("%d\n",&t);

        int sum = 0;
        //printf("%d-------\n",t);
        while(t--)
        {
            // cout<<"--"<<sum<<endl;
            char line;
            while((line=getchar())!='\n')
            {
                //cout<<line<<" "<<mapping[line]<<endl;
                sum = sum + mapping[line +128];
            }
        }
        printf("%d.%.02d$\n",sum/100,sum%100);
    }

    return 0;
}
