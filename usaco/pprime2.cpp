/*
ID: gaurav91
PROG: pprime
LANG: C++
*/

#include <fstream>
#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include<cstring>

#define NUM  11000

using namespace std;
vector<int> primes;
set<int> res;
int ispri[NUM] = {0};

bool result(int N)
{
    if(N==0 || N==1) return false;

    bool flag = false;
    if(N<=NUM)
        flag = !ispri[N];
    else
    {
        flag = true;
        int sq = sqrt(N);
        for(vector<int>::iterator it = primes.begin(); it!=primes.end() && *it<=sq; it++)
        {
            if(N % *it ==0)
            {
                flag = false;
                break;
            }
        }
    }
    return flag;
}
int main()
{
    ofstream off("pprime.out");
    ifstream iff("pprime.in");

    int n= NUM;
    int m = sqrt(n);
    ispri[0] = 1;
    ispri[1] = 1;

    for(int i=2; i<=m; i++)
    {
        if(!ispri[i])
        {
            for(int j=i*i; j<n; j=i+j)
            {
                ispri[j] = 1;
            }
        }
    }
    for(int i=2; i<n; i++)
    {
        if(!ispri[i])
        {
            primes.push_back(i);
        }
    }
    int N,M;
    iff>>N>>M;

    int d1,d2,d3,d4;
    for (d1 = 0; d1 <= 9; d1++)  	/* only odd; evens aren't so prime */
    {
        for (d2 = 0; d2 <= 9; d2++)
        {
            for (d3 = 0; d3 <= 9; d3++)
            {
                for (d4 = 0; d4 <= 9; d4++)
                {
                    int p1 = d1*10000000 + d2*1000000 + d3*100000 + d4*10000+  d4*1000 + d3*100 + d2*10 + d1;
                    int p2 = d1*1000000 + d2*100000 + d3*10000 + d4*1000 +   d3*100 + d2*10 + d1;
                    while(p1%10==0 && p1)
                    {
                        p1 = p1/10;
                    }
                    while(p2%10==0 && p2)
                    {
                        p2 = p2/10;
                    }
                    if(p1>= N  && p1<=M && result(p1))
                    {
                        res.insert(p1);
                    }
                    if(p2>= N  && p2<=M && result(p2))
                    {
                        res.insert(p2);
                    }
                }
            }
        }
    }

    for(set<int>::iterator it = res.begin(); it!=res.end(); it++)
    {
        off<<*it<<endl;
    }

    return 0;
}


















