#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <set>
#include <vector>
#include<map>
#include<cstdio>
#include<stack>
#include<cstring>
#include<climits>
#include<cmath>
using namespace std;

map<int, int> fib;

void fillfib()
{
    int arr[150];
    fib[1] = 0;
    fib[2] = 1;
    arr[0] = 1;
    arr[1] = 2;
    int p = 1;
    while(arr[p]>0)
    {
        p++;
        arr[p] = arr[p-1] + arr[p-2];
        fib[arr[p]] = p;
    }
}

int main()
{
    fillfib();
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n, i;
        int nums[150];
        char str[150];
        char output[150];
        memset(output, ' ', sizeof(output));

        scanf("%d",&n);
        for(i=0; i<n; i++)
        {
            scanf("%d",&nums[i]);
        }
        getchar();
        scanf("%[^\n]", str);
        int counter = 0, sie = 0;
        for(i=0; str[i] && counter<n; i++)
        {
            if(isupper(str[i]))
            {
                int cur = fib[nums[counter]];
                sie = max(sie, cur);
                output[cur] = str[i];
                counter++;
            }
        }
        output[sie+1] = '\0';
        printf("%s\n",output);
    }
    return 0;
}


