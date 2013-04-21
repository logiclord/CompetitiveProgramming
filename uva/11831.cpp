#include<cstdio>
#include<vector>
#include<climits>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cctype>
#include<iostream>
#include<cstdlib>
#include<set>

using namespace std;

int main()
{
    int n,m,s;
    char data[101][101];

    while(scanf("%d%d%d",&n,&m,&s) && (n|m|s))
    {
        int count  = 0;
        int x,y, cur;
        char state[] = {'N','L','S','O'};
        char tmp;
        for(int i=0; i<n; i++)
        {
            getchar();
            for(int j=0; j<m; j++)
            {
                scanf("%c",&data[i][j]);
                if(data[i][j] == 'N' || data[i][j] == 'S' ||data[i][j] == 'L' ||data[i][j] == 'O')
                {
                    x= i;
                    y= j;
                }
            }
        }
        if(data[x][y] == 'N' )
            cur = 0;
        if(data[x][y] == 'S' )
            cur = 2;
        if(data[x][y] == 'L' )
            cur = 1;
        if(data[x][y] == 'O' )
            cur = 3;

        getchar();
        for(int i=0; i<s; i++)
        {
            scanf("%c",&tmp);
            if(tmp == 'D')
            {
                cur = (cur + 1)%4;
            }
            else if(tmp == 'E')
            {
                cur = (cur - 1 + 4)%4;
            }
            else if(tmp == 'F')
            {
                if(state[cur]=='O' && y>0 && data[x][y-1] != '#')
                {
                    data[x][y] = '.';
                    y--;
                }
                else  if(state[cur]=='L' && y+1<m &&  data[x][y+1]!='#')
                {
                    data[x][y] = '.';
                    y++;
                }
                else  if(state[cur]=='S' && x+1<n && data[x+1][y] != '#')
                {
                    data[x][y] = '.';
                    x++;
                }
                else  if(state[cur]=='N' && x>0 && data[x-1][y] != '#')
                {
                    data[x][y] = '.';
                    x--;
                }

                if(data[x][y] == '*')
                {
                    count++;
                }
                data[x][y] = state[cur];
            }
        }
        printf("%d\n",count);
    }
}
