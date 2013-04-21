/*
ID: gaurav91
PROG: gift1
LANG: C++
*/

#include<fstream>
#include<iostream>
#include<map>
#include<string>

using namespace std;

int main()
{
    map<string,int> data;
    map<int,map<string,int>::iterator> order;
    string temp;

    int n;
    ofstream off("gift1.out");
    ifstream iff("gift1.in");
    iff>>n;
    for(int i=0;i<n;i++)
    {
        iff>>temp;
        order.insert(pair<int,map<string,int>::iterator>(i,(data.insert(pair<string,int>(temp,0))).first));
    }
    for(int i=0;i<n;i++)
    {
        int total,num,div;
        iff>>temp;
        iff>>total>>num;
        if(num==0) continue;
        data[temp] = data[temp] + total%num - total;
        div = total/num;
        while(num--)
        {
            iff>>temp;
            data[temp] += div;
        }
    }

    for(map<int,map<string,int>::iterator>::iterator it=order.begin(); it!=order.end(); it++)
    {
        off<<it->second->first<<" "<<it->second->second<<endl;
    }
    return 0;
}



