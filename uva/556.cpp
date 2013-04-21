#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

void transit(char from, char to, int &r, int &c, char &d)
{
    if(from == 'e')
    {
        switch(to)
        {
        case 'r':
        {
            r = 1;
            c = 0;
            break;
        }
        case 'f':
        {
            r =0 ;
            c = 1 ;
            break;
        }
        case 'l':
        {
            r = -1;
            c = 0 ;
            break;
        }
        case 'b':
        {
            r = 0;
            c = -1 ;
            break;
        }
        }
    }
    if(from == 'w')
    {
        switch(to)
        {
        case 'r':
        {
            r = -1;
            c =0  ;
            break;
        }
        case 'f':
        {
            r = 0;
            c = -1 ;
            break;
        }
        case 'l':
        {
            r = 1;
            c =0 ;
            break;
        }
        case 'b':
        {
            r = 0;
            c = 1 ;
            break;
        }
        }
    }
    if(from == 'n')
    {
        switch(to)
        {
        case 'r':
        {
            r = 0;
            c = 1 ;
            break;
        }
        case 'f':
        {
            r = -1;
            c = 0 ;
            break;
        }
        case 'l':
        {
            r = 0;
            c = -1 ;
            break;
        }
        case 'b':
        {
            r = 1;
            c =0  ;
            break;
        }
        }
    }
    if(from == 's')
    {
        switch(to)
        {
        case 'r':
        {
            r = 0;
            c = -1 ;
            break;
        }
        case 'f':
        {
            r = 1;
            c = 0 ;
            break;
        }
        case 'l':
        {
            r = 0;
            c =1  ;
            break;
        }
        case 'b':
        {
            r = -1;
            c =0  ;
            break;
        }
        }
    }
    if(r == -1 && c == 0)
        d = 'n';
    else if(r == 0 && c == 1)
        d = 'e';
    else if(r == 1 && c == 0)
        d = 's';
    else if(r == 0 && c == -1)
        d = 'w';
}

int main(void)
{
    int m,n;
    scanf("%d%d",&m,&n);
    while (!(m==0 && n==0))
{
        int maze[101][101] = {0};
        int visited[101][101] = {0};
        int frequency[10] = {0};
        for(int i=0; i<m; i++)
        {
            getchar();
            for(int j=0; j<n; j++)
            {
                char t;
                scanf("%c",&t);
                maze[i][j] = t - '0';
            }
        }
        /*
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                printf("%d ",maze[i][j]);
            }
            cout<<endl;
        }
 */
        int sr = m-1, sc = 0;
        int cr = sr, cc = sc;
        char going = 'e';
        do
        {

            //cout<<going<<"\t";
            char tries[] = {'r', 'f', 'l', 'b'};
            int dr=0,dc=0;
            char newDirection = going;
            for(int i=0; i<4; i++)
            {
                transit(going, tries[i], dr, dc, newDirection);
                if((cr+dr)>=0 && (cr+dr)<m && (cc + dc)>=0 && (cc + dc)<n && maze[cr + dr][cc + dc] == 0)
                {
                    cr = cr + dr;
                    cc = cc + dc;
                    going = newDirection;
                    break;
                }
            }
          // cout<<cr<<"\t"<<cc<<endl;
            visited[cr][cc]++;
        }
        while(!(cr == sr && cc==sc));
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(maze[i][j]==0)
                {
                    frequency[visited[i][j]]++;
                }
            }
        }
        for(int i=0; i<5; i++)
        {
            printf("%3d",frequency[i]);
        }
        printf("\n");
            scanf("%d%d",&m,&n);
    }
    return 0;
}
