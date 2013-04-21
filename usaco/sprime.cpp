/*
ID: gaurav91
PROG: sprime
LANG: C++
*/

#include <fstream>
#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include<cstring>

#define NUM  100000

using namespace std;

ofstream off("sprime.out");
ifstream iff("sprime.in");
int ispri[NUM] = {0};
vector<int> primes;
int K;

bool isprime(int N)
{
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

void super(int prev,int digit)
{
    if(isprime(prev))
    {
        if(digit==K)
        {
            off<<prev<<endl;
        }
        else
        {
            for(int i=1;i<=9;i=i+2)
            {
                super(prev*10 + i,digit+1);
            }
        }
    }
}

int main()
{

    int n= NUM;
    int m = sqrt(n);
    ispri[0] = 1;
    ispri[1] = 1;
    int i = 2;

    if(!ispri[i])
    {
        for(int j=i*i; j<n; j=i+j)
        {
            ispri[j] = 1;
        }
    }

    for(i=3; i<=m; i=i+2)
    {
        if(!ispri[i])
        {
            for(int j=i*i; j<n; j=i+j)
            {
                ispri[j] = 1;
            }
        }
    }
    for(i=2; i<NUM; i++)
    {
        if(!ispri[i])
        {
            primes.push_back(i);
        }
    }

    iff>>K;
    super(2,1);
    super(3,1);
    super(5,1);
    super(7,1);

    return 0;
}


















