#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    string str;
    while(cin>> str && str[0]!='#')
    {
        if(next_permutation(str.begin(),str.end()))
        {
            cout<<str<<endl;
        }
        else
        {
            printf("No Successor\n");
        }

    }
    return 0;
}
