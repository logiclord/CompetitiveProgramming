#include<cstdio>
#include<vector>
#include<climits>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cctype>
#include<iostream>
#include<cstdlib>

using namespace std;

string convertToString(int n)
{
    string str = "";
    while(n)
    {
        str.push_back(n%10 + '0');
        n = n/10;
    }
    str.assign(str.rbegin(), str.rend());
    return str;
}

string generateString(int s[][100], int k, int i, int j)
{
    if(i==j)
    {
        string ret = "A";
        ret.append(convertToString(i));
        return ret;
    }
    else if(i<j)
    {
        string ret = "";
        ret += "("+generateString(s,s[i][k],i,k)+ " x "+ generateString(s,s[k+1][j],k+1,j)+")";
        return ret;
    }
    return "";
}

int main()
{
    int n, testc = 1;
    while(scanf("%d",&n) && n)
    {
        int x,y, index = 2;
        int p[100];
        int m[100][100];
        int s[100][100];

        for(int i=0; i<100; i++)
        {
            for(int j=0; j<100; j++)
            {
                m[i][j] = INT_MAX;
                s[i][j] = INT_MAX;
            }
        }
        scanf("%d%d",&x,&y);
        p[0] = x;
        p[1] = y;
        for(int i=1; i<n; i++)
        {
            scanf("%d%d",&x,&y);
            p[index] = y;
            index++;
        }
        for(int i=1; i<=n; i++)
        {
            m[i][i] = 0;
        }

        for(int L=2; L<=n; L++)
        {
            for(int i=1; i<=n-L+1; i++)
            {
                int j = i+L-1;
                for(int k=i; k<j; k++)
                {
                    int q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                    if(q<m[i][j])
                    {
                       // cout<<i<<" "<<j<<" "<<m[i][j]<<endl;
                        m[i][j] = q;
                        s[i][j] = k;
                    }
                }
            }
        }
       cout<<"Case "<<testc<<":"<<" "<<generateString(s, s[1][n], 1, n)<<endl;
       testc++;
    }
    return 0;
}



