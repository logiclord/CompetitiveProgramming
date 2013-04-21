#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int nextStep(int a[][3])
{
    //cout<<"called\n";
    int sum = 0;
    int b[3][3] = {0};
    int row[] = {-1,1,0,0};
    int col[] = {0,0,-1,1};

    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            int cur = 0;
            for(int k=0; k<4; k++)
            {
                if(i+row[k] >=0 && i+row[k] <3 && j+col[k]>=0 && j+col[k]<3)
                {
                    cur += a[i+row[k]][j+col[k]];
                }
            }
            b[i][j] = cur%2;
           // cout<<b[i][j] <<"\t";
        }
        //cout<<endl;
    }
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            a[i][j]= b[i][j];
            sum += a[i][j];
        }
    }
    return sum;
}

int main()
{
    int t;
    scanf("%d\n",&t);
    while(t--)
    {
        int a[3][3];
        int sum = 0, val = -1;
        //getchar();
       // getchar();
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                char c;
                cin>> c;
                 a[i][j] =  c - '0';
                sum += a[i][j];
            }
        }
        /*
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                cout<<a[i][j]<<"\t";
            }
            cout<<endl;
        }*/
        if(sum!=0)
        {
            val = 0;
            while(nextStep(a)!=0)
            {
                val++;
            }
        }
        printf("%d\n",val);
    }
    return 0;
}
