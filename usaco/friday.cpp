/*
ID: gaurav91
PROG: friday
LANG: C++
*/

#include<iostream>
#include<fstream>

using namespace std;

int days[7] = {0};

int main()
{
    ofstream off("friday.out");
    ifstream iff("friday.in");
    int n;
    iff>>n;

    int current = 0;
    for(int i=0; i<n; i++)
    {
        int year = 1900+i;
        for(int j=1; j<=12; j++)
        {
            days[current] = days[current] + 1;
            int num_days = 31;
            if(j==4 || j==6 || j==9 || j==11)
                num_days = 30;
            else if(j==2 && ((year%4==0 && year%100!=0) || year%400==0))
                num_days = 29;
            else if(j==2)
                num_days = 28;

            current = (current + num_days%7)%7;

        }
    }
    off<<days[0];
    for(int i=1; i<7; i++)
    {
        off<<" "<<days[i];
    }
    off<<endl;

    return 0;
}


