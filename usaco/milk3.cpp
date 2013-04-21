/*
ID: gaurav91
PROG: milk3
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<set>
#include<vector>
#include<algorithm>


using namespace std;


int data[21][21][21] = {false};
int a,b,c;
set<int> st;

void setmilk(int i ,int j,int k)
{
    if(data[i][j][k])
        return;
    data[i][j][k] = true;

    if(i==0)
        st.insert(k);

    if(k>0)
    {
        if(i+k>a)
            setmilk(a,j,i+k-a);
        else
            setmilk(i+k,j,0);

        if(j+k>b)
            setmilk(i,b,j+k-b);
        else
            setmilk(i,j+k,0);
    }

    if(i>0)
    {
        if(j+i>b)
            setmilk(i+j-b,b,k);
        else
            setmilk(0,i+j,k);

        if(k+i>c)
            setmilk(i+k-c,j,c);
        else
            setmilk(0,j,i+k);
    }

    if(j>0)
    {
        if(i+j>a)
            setmilk(a,i+j-a,k);
        else
            setmilk(i+j,0,k);

        if(k+j>c)
            setmilk(i,k+j-c,c);
        else
            setmilk(i,0,k+j);
    }
}

int main()
{
    ofstream off("milk3.out");
    ifstream iff("milk3.in");
    iff>>a>>b>>c;
    setmilk(0,0,c);

    set<int>::iterator it = st.begin();
    off<<*it;
    it++;
    for(; it!=st.end(); it++)
    {
        off<<" "<<*it;
    }

    off<<"\n";

    return 0;
}


