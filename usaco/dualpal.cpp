/*
ID: gaurav91
PROG: dualpal
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<cstring>

using namespace std;


bool convert(int n,int b)
{
    char res[100];
    char mp[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int i=0;
    while(n)
    {
        res[i] = mp[n%b];
        n = n/b;
        i++;
    }
    res[i] = '\0';

    int k=i-1;
    for(int j=0; j<i/2; j++,k--)
    {
        if(res[j] != res[k])
            return false;
    }

    return true;
}
int main()
{
    ofstream off("dualpal.out");
    ifstream iff("dualpal.in");
    int n,s;
    iff>>n>>s;
    s++;
    while(n>0)
    {

        int count = 0;
        for(int i=2; i<=10 && count<2; i++)
        {
            if(convert(s,i))
                count++;
        }
        if(count>=2)
        {
            off<<s<<"\n";
            n--;
        }
        s++;
    }
    return 0;
}

