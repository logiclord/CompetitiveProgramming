#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<vector>
#include<map>
#include<cmath>
#include<cctype>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000

int main()
{
    char str[1000000];
    while(scanf("%s",str) != EOF)
    {
        char play[100][100];
        int board[100][100];
        for(int i=0; i<8; i++)
        {
            for(int j=0; j<8; j++)
            {
                play[i][j] = '_';
                board[i][j] = 0;
            }
        }

        int r=0, c=0;
        int rOffset[] = {-2,-2,-1,-1,1,1,2,2};
        int cOffset[] = {-1,1,2,-2,2,-2,1,-1};

        for(int i=0; str[i]!= '\0'; i++)
        {
            if(str[i] == '/')
            {
                r++;
                c=0;
            }
            else if(isdigit(str[i]))
            {
                c = c + (str[i] - '0');
            }
            else
            {
                play[r][c] = str[i];
                c++;
            }
        }

        for(int i=0; i<8; i++)
        {
            for(int j=0; j<8; j++)
            {
                if(play[i][j] == '_')
                    continue;
                char cur = tolower(play[i][j]);
                //cout<<play[i][j]<<" "<<i<<" "<<j<<endl;
                int r=i, c = j;
                board[r][c] = 1;
                if(cur == 'q' || cur == 'r')
                {
                    // cout<<"q r\n";
                    int index = 0;
                    index = r-1;
                    while(index>=0 && play[index][c] == '_')
                    {
                        board[index][c] = 1;
                        index--;
                    }
                    index = c-1;
                    while(index>=0 && play[r][index] == '_')
                    {
                        board[r][index] = 1;
                        index--;
                    }
                    index = r+1;
                    while(index<8 && play[index][c] == '_')
                    {
                        board[index][c] = 1;
                        index++;
                    }
                    index = c+1;
                    while(index<8 && play[r][index] == '_')
                    {
                        board[r][index] = 1;
                        index++;
                    }
                }
                if(cur == 'k' )
                {
                    //cout<<"k  \n";
                    if(r+1<8)
                        board[r+1][c] = 1;
                    if(r>0)
                        board[r-1][c] = 1;
                    if(c+1<8)
                        board[r][c+1] = 1;
                    if(c>0)
                        board[r][c-1] = 1;
                    if(r+1 < 8 && c+1<8)
                        board[r+1][c+1] = 1;
                    if(r-1>=0 && c-1>=0)
                        board[r-1][c-1] = 1;
                    if(r-1>=0 && c+1<8)
                      board[r-1][c+1] = 1;
                    if(r+1>=0 && c-1<8)
                      board[r+1][c-1] = 1;
                }
                if(cur == 'n')
                {
                    for(int index = 0; index<8; index++)
                    {
                        if((r + rOffset[index]) >=0 && (r + rOffset[index])<8 && (c + cOffset[index])>=0 && (c + cOffset[index])<8)
                        {
                            board[r + rOffset[index]][c + cOffset[index]] = 1;
                        }
                    }
                }

                if(play[i][j] == 'p' && (r+1)<8)
                {
                    //  cout<<"p \n";
                    if((c-1)>=0)
                        board[r+1][c-1] = 1;
                    if((c+1)<8)
                        board[r+1][c+1] = 1;
                }
                if(play[i][j] == 'P' && (r-1)>=0)
                {
                    //cout<<"P \n";
                    if((c-1)>=0)
                        board[r-1][c-1] = 1;
                    if((c+1)<8)
                        board[r-1][c+1] = 1;
                }

                if(cur == 'q' || cur == 'b')
                {
                    // cout<<"q b\n";
                    int ri = r+1, ci = c+1;
                    while(ri>=0 && ri<8 && ci>=0 && ci<8 && play[ri][ci] == '_')
                    {
                        board[ri][ci] = 1;
                        ri++;
                        ci++;
                    }
                    ri = r+1, ci = c-1;
                    while(ri>=0 && ri<8 && ci>=0 && ci<8 && play[ri][ci] == '_')
                    {
                        board[ri][ci] = 1;
                        ri++;
                        ci--;
                    }
                    ri = r-1, ci = c+1;
                    while(ri>=0 && ri<8 && ci>=0 && ci<8 && play[ri][ci] == '_')
                    {
                        board[ri][ci] = 1;
                        ri--;
                        ci++;
                    }
                    ri = r-1, ci = c-1;
                    while(ri>=0 && ri<8 && ci>=0 && ci<8 && play[ri][ci] == '_')
                    {
                        board[ri][ci] = 1;
                        ri--;
                        ci--;
                    }
                }
                for(int i=0; i<8; i++)
                {
                    for(int j=0; j<8; j++)
                    {
                       // cout<<board[i][j]<<" "<<(char)tolower(play[i][j])<<"\t";
                    }
                  //  cout<<endl;
                }
                //  cout<<board[i][j]<<endl;

            }
        }

        int counter = 0;
        for(int i=0; i<8; i++)
        {
            for(int j=0; j<8; j++)
            {
                if(board[i][j] == 0 && play[i][j] == '_')
                {
                    counter++;
                }
            }
        }
        printf("%d\n",counter);
    }
    return 0;
}
