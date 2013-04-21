/*
ID: gaurav91
PROG: clocks
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<map>
#include<vector>
#include<algorithm>
#include<queue>


using namespace std;

struct state
{
    vector<short> clock;
    vector<short> move;
};

int makehash(vector<short> &st)
{
    int val = 0;
    for(vector<short>::iterator it = st.begin(); it!=st.end(); it++)
    {
        val = val*10 + *it;
    }
    return val;
}
bool isokay(vector<short> &st)
{
    for(vector<short>::iterator it = st.begin(); it!=st.end(); it++)
    {
        if(*it!=4)
        {
            return false;
        }
    }
    return true;
}
map<int,bool> data;
//                    a,b,c,d,e,f,g,h,i
bool moves[9][9] = {   1,1,0,1,1,0,0,0,0,
                       1,1,1,0,0,0,0,0,0,
                       0,1,1,0,1,1,0,0,0,
                       1,0,0,1,0,0,1,0,0,
                       0,1,0,1,1,1,0,1,0,
                       0,0,1,0,0,1,0,0,1,
                       0,0,0,1,1,0,1,1,0,
                       0,0,0,0,0,0,1,1,1,
                       0,0,0,0,1,1,0,1,1
                   };

int main()
{
    ofstream off("clocks.out");
    ifstream iff("clocks.in");
    state cur;

    for(int i=0; i<9 ; i++)
    {
        short temp;
        iff>>temp;
        cur.clock.push_back(temp/3);
    }

    queue<state> myq;
    myq.push(cur);

    bool found = false;
    int foundmoves = 99999999;
    vector<short> answermoves;
    int num_moves = 0;
    while(!myq.empty() )
    {
        //cout<<myq.size()<<endl;
        cur = myq.front();
        myq.pop();
        int hashed = makehash(cur.clock);

        if(data[hashed]!=true)
        {
            data[hashed] = true;
            for(int i=0; i<9 && (found==false ||  (cur.move.size()+1)<=num_moves); i++)
            {
                state nex;
                nex.clock.assign(cur.clock.begin(),cur.clock.end());
                nex.move.assign(cur.move.begin(),cur.move.end());
                nex.move.push_back(i+1);
                for(int j=0; j<9; j++)
                {
                    if(moves[i][j])
                        nex.clock[j] = nex.clock[j]%4 + 1;
                }
                if(isokay(nex.clock))
                {
                    int temp = makehash(nex.move);
                    if(!found || temp<foundmoves)
                    {
                        foundmoves = temp;
                        num_moves = nex.move.size();
                        answermoves.assign(nex.move.begin(),nex.move.end());
                    }
                    found = true;
                }
                myq.push(nex);
            }
        }

    }
    vector<short>::iterator it = answermoves.begin();
    off<<*it;
    it++;
    for(; it!=answermoves.end(); it++)
    {
        off<<" "<<*it;
    }
    off<<"\n";

    return 0;
}


