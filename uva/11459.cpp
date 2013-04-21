#include <cstdio>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <map>
using namespace std;



int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int nplayer, njump, ndice, from,to;
        scanf("%d%d%d",&nplayer, &njump, &ndice);
        vector<int> players(nplayer,1);
        map<int,int> jump;
        while(njump--)
        {
            scanf("%d%d",&from,&to);
            jump.insert(make_pair(from,to));
        }
        int dice;
        int gameEnd = false;
        for(int i=0; i<ndice; i++)
        {
            int current_player = i%nplayer;
            scanf("%d",&dice);
            if(!gameEnd)
            {
                players[current_player] += dice;
                if(jump.find(players[current_player])!= jump.end())
                {
                    players[current_player] = jump[players[current_player]];
                }
                if(players[current_player] >=100)
                {
                    players[current_player] = 100;
                    gameEnd = true;
                }
            }
        }

        for(int i=0; i<nplayer; i++)
        {
            printf("Position of player %d is %d.\n",(i+1),players[i]);
        }
    }
    return 0;
}
