#include<cstdio>
#include<vector>
#include<climits>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cctype>
#include<iostream>

using namespace std;

using namespace std;

/* Finds longest strictly increasing subsequence. O(n log k) algorithm. */
void find_lds(vector<int> &a,int inc[])
{
    vector<int> b;
    vector<int> p(a.size());
    int u, v;

    if (a.empty()) return;
    inc[0] = 1;
    b.push_back(0);

    for (size_t i = 1; i < a.size(); i++)
    {
        // If next element a[i] is greater than last element of current longest subsequence a[b.back()], just push it at back of "b" and continue
        if (a[b.back()] > a[i])
        {
            p[i] = b.back();
            b.push_back(i);
            inc[i] = inc[p[i]] +1;
            continue;
        }

        // Binary search to find the smallest element referenced by b which is just bigger than a[i]
        // Note : Binary search is performed on b (and not a). Size of b is always <=k and hence contributes O(log k) to complexity.
        for (u = 0, v = b.size()-1; u < v;)
        {
            int c = (u + v) / 2;
            if (a[b[c]] > a[i]) u=c+1;
            else v=c;
        }

        // Update b if new value is smaller then previously referenced value
        if (a[i] > a[b[u]])
        {
            if (u > 0)
            {
                p[i] = b[u-1];
                inc[i] = inc[p[i]] + 1;
            }
            else
            {
                inc[i] = 1;
            }
            b[u] = i;
        }
    }

    // for (u = b.size(), v = b.back(); u--; v = p[v]) b[u] = v;
}

/* Finds longest strictly increasing subsequence. O(n log k) algorithm. */
void find_lis(vector<int> &a, int inc[])
{
    vector<int> b;
    vector<int> p(a.size());
    int u, v;

    if (a.empty()) return;

    b.push_back(0);
    inc[0] = 1;

    for (size_t i = 1; i < a.size(); i++)
    {
        // If next element a[i] is greater than last element of current longest subsequence a[b.back()], just push it at back of "b" and continue
        if (a[b.back()] < a[i])
        {
            p[i] = b.back();
            b.push_back(i);
            inc[i] = inc[p[i]] + 1;
            continue;
        }

        // Binary search to find the smallest element referenced by b which is just bigger than a[i]
        // Note : Binary search is performed on b (and not a). Size of b is always <=k and hence contributes O(log k) to complexity.
        for (u = 0, v = b.size()-1; u < v;)
        {
            int c = (u + v) / 2;
            if (a[b[c]] < a[i]) u=c+1;
            else v=c;
        }

        // Update b if new value is smaller then previously referenced value
        if (a[i] < a[b[u]])
        {
            if (u > 0)
            {
                p[i] = b[u-1];
                inc[i] = inc[p[i]] + 1;
            }
            else
            {
                inc[i] = 1;
            }
            b[u] = i;

        }
    }

    // for (u = b.size(), v = b.back(); u--; v = p[v]) b[u] = v;
}

/* Example of usage: */
#include <cstdio>
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int tmp;
        vector<int> seq,seq2; // seq : Input Vector
        for(int i=0; i<n; i++)
        {
            scanf("%d",&tmp);
            seq2.push_back(tmp);
        }
        seq.assign(seq2.rbegin(), seq2.rend());
        int inc[10000] = {0};
        int dec[10000] = {0};
        int maxi = 0;
        find_lis(seq, inc);
        find_lds(seq, dec);
        for(int i=0;i<n;i++)
        {
           // cout<< inc[i] <<" "<< dec[i]<<endl;
            maxi= max(maxi, inc[i] + dec[i]-1);
        }
        cout<<maxi<<endl;

    }
    return 0;
}

