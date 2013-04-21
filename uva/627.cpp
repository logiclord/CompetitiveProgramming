#include <cstdio>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <set>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <deque>
#include <map>
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t)
    {
        int mul = (t%4 == 0) ? t: ((t/4 +1)*4) ;
        int sheets = mul/4;
        int front = 1;
        printf("Printing order for %d pages:\n",t);
        for(int i=1; i<= sheets; i++)
        {
            if(t<mul)
            {
                printf("Sheet %d, front: Blank, %d\n",i, front);
            }
            else
            {
                printf("Sheet %d, front: %d, %d\n",i, mul, front);
            }

            front++;
            mul--;

            if(t<mul && front>t)
            {
                //printf("Sheet %d, back : Blank, Blank\n");
            }
            else if(t< mul && front<=t)
            {
                printf("Sheet %d, back : %d, Blank\n",i, front);
            }
            else
            {
                printf("Sheet %d, back : %d, %d\n",i, front, mul);
            }
            front++;
            mul--;
        }
        scanf("%d",&t);
    }
    return 0;
}





