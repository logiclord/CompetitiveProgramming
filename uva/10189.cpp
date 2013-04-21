#include <cstdio>
#include <vector>
#include <iostream>
#include <cstdlib>
using namespace std;



int main()
{
    int m,n,num=1, Flag =0;
    scanf("%d%d",&m,&n);
    while(!(m==0 && n==0))
    {
        char value[150][150],cur;
        int rval[] = {-1,0,1,-1,1,-1,0,1};
        int cval[] = {-1,-1,-1,0,0,1,1,1};
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                value[i][j] = '0';
            }
        }

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                cin>>cur;
                if(cur == '*')
                {
                    value[i][j] = '*';
                    for(int k=0; k<8; k++)
                    {
                        if(value[i+rval[k]][j+cval[k]] != '*' && (i+rval[k]) >=0 && (i+rval[k]) <m && (j+cval[k])>=0 && (j+cval[k])<n)
                        {
                            value[i+rval[k]][j+cval[k]] = value[i+rval[k]][j+cval[k]] + 1;
                        }
                    }
                }
            }
        }

        if (Flag==1)
            printf("\n");
        Flag = 1;
        cout<<"Field #"<<num<<":\n";
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<value[i][j];
            }
            cout<<endl;
        }
        num++;
        scanf("%d%d",&m,&n);
    }
    return 0;
}
