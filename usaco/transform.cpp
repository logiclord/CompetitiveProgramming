/*
ID: gaurav91
PROG: transform
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>

using namespace std;

void input(char dat[10][10],int n,ifstream &iff)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            iff>>dat[i][j];
        }
    }
}
bool check(char before[10][10],char after[10][10],int n,int t)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            // 90   data[j][n-1-i] = dat[i][j] ;
            //180   data[n-i-1][n-1-j] = dat[i][j] ;
            //270  data[n-j-1][i] = dat[i][j] ;
            if(before[i][j]!=after[i][j] && t==0)
                return false;
            else if(before[i][j]!=after[j][n-1-i] && t==90)
                return false;
            else if(before[i][j]!=after[n-i-1][n-1-j] && t==180)
                return false;
            else if(before[i][j]!=after[n-j-1][i] && t==270)
                return false;
            else if(before[i][j]!=after[i][n-j-1] && t==-1)
                return false;
        }
    }

    return true;
}

void refl(char data[10][10],char re[10][10],int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            re[i][n-j-1] = data[i][j];
        }
    }
}
void output(char data[10][10],int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<< data[i][j];
        }
        cout<<"\n";
    }
}
int main()
{
    ofstream off("transform.out");
    ifstream iff("transform.in");
    int n;
    iff>>n;
    char before[10][10],after[10][10],ref[10][10];
    input(before,n,iff);
    input(after,n,iff);
    refl(before,ref,n);

    if(check(before,after,n,90))
        off<<1;
    else if(check(before,after,n,180))
        off<<2;
    else if(check(before,after,n,270))
        off<<3;
    else if(check(before,after,n,-1))
        off<<4;
    else if(check(ref,after,n,90) || check(ref,after,n,180) || check(ref,after,n,270))
        off<<5;
    else if(check(before,after,n,0))
        off<<6;
    else
        off<<7;

    off<<"\n";
    return 0;
}




