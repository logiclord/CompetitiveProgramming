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
    int n, t=0;
    scanf("%d",&n);
    getchar();
    while(n--)
    {
        int dim = 1, i = 0 , len = 0;
        bool isset = true;
        char line[10000];
        char cur = 'a';
        while(scanf("%c",&cur) && cur!='\n')
        {
            if(isalnum(cur))
            {
                line[i] = cur;
                i++;
            }
        }
        len = i;
        dim = sqrt(len);
        //cout<<line<<endl<<dim<<endl;
        if(dim*dim != len)
        {
            isset = false;
        }
        // must be a pallindrome
        for(int j = len - 1,  i=0; isset && i<=len/2; j--, i++)
        {
            if(line[j] != line [i])
            {
                isset = false;
                break;
            }
        }
       // cout<<isset<<endl;
        for(int offset = 1; isset && offset <= dim; offset++)
        {
           // cout<<offset<<endl;
            int j = len - offset;
            i = offset - 1;
            while(i < len && j >= 0)
            {
                if(line[i] != line[j])
                {
                    isset = false;
                    break;
                }
                i = i + dim;
                j = j - dim;
            }
        }
        //cout<<isset<<endl;

        t++;
        printf("Case #%d:\n",t);
        if(isset)
        {
            printf("%d\n", dim);
        }
        else
        {
            printf("No magic :(\n");
        }
    }
    return 0;
}
