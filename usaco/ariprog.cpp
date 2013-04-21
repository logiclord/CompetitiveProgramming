/*
ID: gaurav91
PROG: ariprog
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<set>
#include<vector>
#include<algorithm>


using namespace std;


bool data[150000]= {false};
vector<int> v;
set<pair<int,int> > st;

bool checkap(int a,int d,int n)
{
    if(n==0)
        return true;
    if(a > 140000)
        return false;

    return data[a] && checkap(a+d,d,n-1);
}

int main()
{
    ofstream off("ariprog.out");
    ifstream iff("ariprog.in");
    int n,m;
    iff>>n>>m;

    for(int i=0; i<=m; i++)
        for(int j=0; j<=m; j++)
        {
            int tmp = i*i + j*j;
            if(data[tmp]==false)
            {
                data[tmp] = true;
                v.push_back(tmp);
            }
        }

    sort(v.begin(),v.end());
    int total = v.size();

    for(int i=0; i<total; i++)
        for(int j=i+1; j<total; j++)
        {
            if(checkap(v[i],v[j]-v[i],n))
            {
                st.insert(make_pair(v[j]-v[i],v[i]));
            }
        }

    if(st.size()==0)
        off<<"NONE\n";
    else
        for(set<pair<int,int> > ::iterator it = st.begin(); it!=st.end(); it++)
        {
            off<<it->second<<" "<<it->first<<"\n";
        }
    return 0;
}


