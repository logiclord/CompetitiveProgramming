#include <map>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <cstring>

void exchangeChars(char *s, int i,int j)
{
    char c;
    while(i<j)
    {
        c = *(s+i);
        *(s+i) =  *(s+j);
        *(s+j) = c;
        i++;
        j--;
    }
}

void reverseWords(char *s, int len)
{
    int i=0,j=0;
    while(*(s+i))
    {
        if(isalnum(*(s+i)))
        {
            int j=i+1;
            while(*(s+j) && isalnum(*(s+j)))
            {
                j++;
            }
            exchangeChars(s,i,j-1);
            i = j;
        }
        else
        {
            i++;
        }
    }
    exchangeChars(s,0,len-1);
}

int main()
{
    char s[] = "i like this program very much";
    char *temp = s;
    reverseWords(s,strlen(s));
    printf("%s", s);
    getchar();
    return 0;
}
