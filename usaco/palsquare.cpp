/*
ID: gaurav91
PROG: palsquare
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<cstring>

using namespace std;

bool convert(int n,char res[],int b)
{
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
    ofstream off("palsquare.out");
    ifstream iff("palsquare.in");
    int n;
    iff>>n;

    for(int i=1; i<=300; i++)
    {
        char res[100];
        if(convert(i*i,res,n))
        {
            char res2[100];
            convert(i,res2,n);
            int len = strlen(res2);
            while(len--)
                off<<res2[len];

            off<<" "<<res<<"\n";
        }
    }

    return 0;
}
