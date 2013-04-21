#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <map>
#include <cmath>
using namespace std;

int  p, q, r, s, t, u;
double func(double x)
{
    return (p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u);
}
int main()
{
    while(scanf("%d%d%d%d%d%d",&p, &q, &r, &s, &t, &u) != EOF)
    {
        double l = 0, h= 1, m;
        if(func(l)*func(h)<=0)
        {
            double p;
            while(abs(h-l)>1e-7)
            {
               // cout<<l<<" "<<h<<endl;
                m = (l+h)/2;
                p = func(m);
                if(p>0)
                {
                    l=m;
                }
                else
                {
                    h=m;
                }
            }
           // cout<<m;
            printf("%.4f\n",m);
        }
        else
        {
            printf("No solution\n");
        }
    }
    return 0;
}
