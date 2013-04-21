#include <map>
#include <cstdlib>
#include <queue>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

char *encode(char *s)
{
    char * output = (char *) malloc(strlen(s)*2);
    int i = 0, j= 0, count = 0;
    char currentChar = *(s);
    while(*(s+i))
    {
        if(currentChar!=*(s+i))
        {
            output[j++] = currentChar;
            output[j++] = count+'0';
            currentChar = *(s+i);
            count = 1;
        }
        else
        {
            count++;
        }
        i++;
    }
    output[j++] = currentChar;
    output[j++] = count+'0';
    output[j] = '\0';
    return output;
}


/*driver program to test above function */
int main()
{
    char str[] = "geeksforgeeks";
    char *res = encode(str);
    printf("%s", res);
    getchar();
}

