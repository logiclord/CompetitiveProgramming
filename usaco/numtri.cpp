/*
ID: gaurav91
PROG: numtri
LANG: C++
*/

#include<fstream>
#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<queue>
#include<climits>

using namespace std;

int data[1001][1001];
int main()
{
    ofstream off("numtri.out");
    ifstream iff("numtri.in");
    int r, maxi=0;
    iff>>r;
    for(int i=1; i<=r; i++)
    {
        for(int j=1; j<=i; j++)
        {
            iff>>data[i][j];
        }
    }


    for(int i=2; i<=r; i++)
    {
        for(int j=1; j<=i; j++)
        {
            int l,r,s;
            l=r=s=0;

            if(j!=1) l = data[i-1][j-1];
            //if(j < i-1) r = data[i-1][j+1];
            if(i!=j) s = data[i-1][j];

            data[i][j] =  max(max(l,r),s) + data[i][j];
            maxi = max(maxi,data[i][j]);
        }
    }
    off<<maxi<<endl;

    return 0;
}
