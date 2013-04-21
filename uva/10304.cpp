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


int main()
{
    int n;
    while(scanf("%d",&n)!= EOF)
    {
        int p[251];
        int sum[251]= {0};
        int total = 0;
        int m[251][251];

        for(int i=0; i<n; i++)
        {
            scanf("%d",&p[i]);
            total += p[i];
            sum[i] = total;
        }

        for(int i=0; i<=n; i++)
        {
            m[i][i] = p[i];
        }

        for(int L=1; L<=n; L++)
        {
            for(int i=0; i<n-L+1; i++)
            {
                int j = i+L-1;
                m[i][j] = INT_MAX;
                for(int k=i; k<=j; k++)
                {
                    int sumi = sum[j] - sum[k] ;
                    if(i>0)
                    {
                        sumi = sumi - sum[i-1];
                    }
                    if(k>0)
                    {
                        sumi = sumi + sum[k-1];
                    }
                    int q = sumi + ((k > i)? m[i][k-1]:0) + ((k < j)? m[k+1][j]:0);
                    //cout<<i<<" "<<j<<" "<<q<<endl;
                    if(q < m[i][j])
                    {
                        m[i][j] = q;
                    }
                }
            }
        }
        cout<<m[0][n-1]<<endl;
    }
    return 0;
}



