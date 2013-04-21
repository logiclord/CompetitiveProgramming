#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>

using namespace std;
const int maxn = 1010;

class action
{
public:
    int type;
    int value;
};

stack<int> st;
queue<int> q;
priority_queue<int, vector<int>, less<int> > pq;
int n;
action list[maxn];

bool checkst();
bool checkq();
bool checkpq();

int main()
{
    bool isst, isq, ispq;
    while (!cin.eof())
    {
        cin >> n;
        if(cin.eof()) break;
        while (!q.empty()) q.pop();
        while (!st.empty()) st.pop();
        while (!pq.empty()) pq.pop();
        for (int i=1; i<=n; i++) cin >> list[i].type >> list[i].value;
        isst = checkst();
        isq = checkq();
        ispq = checkpq();
        if(isst+isq+ispq>1) cout << "not sure" << endl;
        else if (isst+isq+ispq==0) cout << "impossible" << endl;
        else
        {
            if(isst) cout << "stack" << endl;
            else if (isq) cout << "queue" << endl;
            else if (ispq) cout << "priority queue" << endl;
        }
    }
    return 0;
}

bool checkst()
{
    for (int i=1; i<=n; i++)
    {
        if(list[i].type==1) st.push(list[i].value);
        else if (list[i].type==2)
        {
            int tmp;
            if(!st.empty())
            {
                tmp = st.top();
                st.pop();
            }
            else return(false);
            if(tmp!=list[i].value) return(false);
        }
    }
    return(true);
}

bool checkq()
{
    for (int i=1; i<=n; i++)
    {
        if(list[i].type==1) q.push(list[i].value);
        else if (list[i].type==2)
        {
            int tmp;
            if(!q.empty())
            {
                tmp = q.front();
                q.pop();
            }
            else return(false);
            if(tmp!=list[i].value) return(false);
        }
    }
    return(true);
}

bool checkpq()
{
    for (int i=1; i<=n; i++)
    {
        if(list[i].type==1) pq.push(list[i].value);
        else if (list[i].type==2)
        {
            int tmp;
            if(!pq.empty())
            {
                tmp = pq.top();
                pq.pop();
            }
            else return(false);
            if(tmp!=list[i].value) return(false);
        }
    }
    return(true);
}
