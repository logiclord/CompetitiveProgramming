#include <map>
#include <cstdlib>
#include <queue>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

void createTable(char pat[], int a[])
{
    int i=2,j=0,len=strlen(pat);
    a[0] = 0;
    a[1] = 0;
    while(i<=len)
    {
        j = a[i-1];
        while(1)
        {
            if(pat[j] == pat[i-1])
            {
                a[i] = j+1;
                break;
            }
            else if(j==0)
            {
                a[i] = 0;
                break;
            }
            else
            {
                j = a[j];
            }
        }
        i++;
    }
}

void kmp(char str[], char pat[])
{
    int f[100];
    createTable(pat,f);
    int i=0,j=0, m = strlen(pat);
    while(str[i])
    {
        if(pat[j] == str[i])
        {
            j++;
            i++;
            if(j==m)
            {
                printf("Match found at %d\n", i);
                j = f[j];
            }
        }
        else if(j==0)
        {
            i++;
        }
        else
        {
            j = f[j];
        }
    }
}

/*driver program to test above function */
int main()
{
    char str[] = "geeksforgeeks";
    char pat[] = "gee";
    kmp(str,pat);
    getchar();
}

