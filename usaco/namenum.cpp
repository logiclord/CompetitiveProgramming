/*
ID: gaurav91
PROG: namenum
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<map>

using namespace std;

long long mapping(string str)
{
    long long ret = 0;
    for(string::iterator it = str.begin(); it!=str.end(); it++)
    {
        int cur = 0;
        switch(*it)
        {
            case 'A':
            case 'B':
            case 'C': cur = 2; break;
            case 'D':
            case 'E':
            case 'F': cur = 3; break;
            case 'G':
            case 'H':
            case 'I': cur = 4; break;
            case 'J':
            case 'K':
            case 'L': cur = 5; break;
            case 'M':
            case 'N':
            case 'O':cur = 6; break;
            case 'P':
            case 'R':
            case 'S':cur = 7; break;
            case 'T':
            case 'U':
            case 'V':cur = 8; break;
            case 'W':
            case 'X':
            case 'Y':cur = 9; break;
        }
        ret = ret*10 + cur;
    }


    return  ret;
}

int main()
{
    ofstream off("namenum.out");
    ifstream iff("namenum.in");
    string res;
    long long str;
    int count = 0;
    iff>>str;
    ifstream iff2("dict.txt");
    while(iff2>>res)
    {
        if(str == mapping(res))
        {
            count++;
            off<<res<<"\n";
        }
    }

    if(!count)
    {
        off<<"NONE\n";
    }

    return 0;
}

