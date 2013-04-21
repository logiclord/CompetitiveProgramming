/*
ID: gaurav91
PROG: milk2
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
    ofstream off("milk2.out");
    ifstream iff("milk2.in");
    vector<pair<int,int> > v;

    int n,j,k;
    int start,last;
    iff>>n;

    for(int i=0; i<n; i++)
    {
        iff>>j>>k;
        v.push_back(pair<int,int>(j,k));
    }
    sort(v.begin(),v.end());

    int maxc = 0;
    int maxd = 0;
    if(n)
    {
        start = v[0].first;
        last = v[0].second;
        maxc = last - start;
    }
    for(int i=1; i<n; i++)
    {
        j = v[i].first;
        k = v[i].second;
        if(j<=last)
        {
            last = max(last,k);
        }
        else
        {
            maxc = max(maxc,last-start);
            maxd = max(maxd,j-last);
            start = j;
            last = k;
        }
    }
    off<<maxc<<" "<<maxd<<endl;
    return 0;
}


