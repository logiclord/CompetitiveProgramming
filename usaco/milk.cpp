/*
ID: gaurav91
PROG: milk
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
    ofstream off("milk.out");
    ifstream iff("milk.in");
    vector<pair<int,int> > v;
    int n,m;
    iff>>n>>m;
    while(m--)
    {
        int i,j;
        iff>>i>>j;
        v.push_back(pair<int,int>(i,j));
    }
    sort(v.begin(),v.end());
    int total = 0;
    for(vector<pair<int,int> >::iterator it = v.begin(); it!=v.end() && n > 0; it++)
    {
        if(it->second >= n)
        {
            total += n*(it->first) ;
            n = 0;
        }
        else
        {
            total += (it->second)*(it->first);
            n = n- it->second;
        }
    }
    off<<total<<"\n";

    return 0;
}
