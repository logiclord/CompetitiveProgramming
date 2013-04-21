/*
ID: gaurav91
PROG: checker
LANG: C++
*/

#include <fstream>
#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include <cstring>
#include <cstdlib>

using namespace std;


int maxi;

int total = 0;
ofstream off("checker.out");
ifstream iff("checker.in");

int columnForRow[20];
bool columnUsed[20] = {0};

void PlaceQueen(int row)
{
    if (row == maxi)
    {
        if(total<3)
        {
            off<<columnForRow[0]+1;
            for(int i=1; i<maxi; i++)
            {
                off<<" "<<columnForRow[i]+1;
            }
            off<<endl;
        }
        total++;
        return;
    }
    for (int i = 0; i < maxi; i++)
    {
        columnForRow[row]=i;

        if(columnUsed[i] == false)
        {
            bool flag = true;
            columnUsed[i] = true;
            for (int i = 0; i < row; i++)
            {
                int diff = abs(columnForRow[i] - columnForRow[row]);
                if (diff == row - i)
                {
                    flag = false;
                    break;
                }
            }
            if(flag)
            {
                PlaceQueen(row+1);
            }
            columnUsed[i] = false;
        }

    }
}
int main()
{
    iff>>maxi;
    PlaceQueen(0);
    off<<total<<endl;
    return 0;
}


















