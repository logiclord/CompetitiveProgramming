/*
ID: gaurav91
PROG: beads
LANG: C++
*/

#include<iostream>
#include<fstream>

using namespace std;

int main()
{
    ofstream off("beads.out");
    ifstream iff("beads.in");
    int n;
    int max=0;
    char data[500];
    iff>>n;
    iff>>data;

    for(int i=0; i<n; i++)
    {
        int j = i, k =(i+1)%n;
        int clock=0, anticl=0;
        cout<<" "<<j<<" "<<k;

        while(data[k]=='w' && clock<=n)
        {
            k = (k+1)%n;
            clock++;
        }
        while(data[j]=='w' && anticl<=n)
        {
            j = (n + (j-1))%n;
            anticl++;
        }
        char jc = data[j],kc = data[k];
        cout<<" "<<jc<<" "<<kc;
        cout<<" "<<j<<" "<<k;

        while((kc==data[k] || data[k]=='w') && clock<=n)
        {
            k = (k+1)%n;
            clock++;
        }
        while(anticl<=n && (jc==data[j] || data[j]=='w') )
        {
            j = (n + (j-1))%n;
            anticl++;
        }
        cout<<" "<<j<<" "<<k;
        cout<<" "<<clock + anticl<<endl;
        if(clock + anticl > n)
        {
            max = n;
            break;
        }
        if(clock + anticl>max)
            max = clock + anticl;

    }
    off<<max<<endl;
    return 0;
}


