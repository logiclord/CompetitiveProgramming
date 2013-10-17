#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<functional>
#include<map>

using namespace std;

#define getIth(num,i) ((num&(1<<i)) > 0)
#define fiddleIth(num,i) (num^(1<<i))

int r,d,s;


struct state
{
	int roomNumber;
	int lightOn;
	bool operator <(const state &s) const 
	{
		if(roomNumber ==  s.roomNumber)
		{
			return lightOn < s.lightOn; 
		}
		return roomNumber < s.roomNumber;
	}

	bool operator ==(const state &s) const 
	{
		bool ret = (roomNumber == s.roomNumber) && (lightOn == s.lightOn); 
		return ret;
	}
};

state createState(int r, int x)
{
	state end;
	end.roomNumber = x;
	end.lightOn = 0;
	return end;
}

void PrintPath(map<state,state> &parent, state start, state end)
{
	if(!(start==end))
	{
		state parentState  = parent[end];
		PrintPath(parent, start, parentState);
		if(parentState.roomNumber != end.roomNumber)
		{
			printf("- Move to room %d.\n", end.roomNumber);
		}
		else
		{
			for(int i=0; i<r; i++)
			{
				if(getIth(end.lightOn, i)!= getIth(parentState.lightOn, i))
				{
					printf("- Switch %s light in room %d.\n", (getIth(end.lightOn, i) ? "on" : "off" ),i+1);
					break;
				}
			}
		}
	}
}

int main()
{
	int villa = 1;
	while(scanf("%d%d%d",&r,&d,&s)!=EOF && (r||d||s))
	{
		int doors[11][11] = {0};
		int control[11][11] = {0};
		int x,y;

		for(int i=0; i <d; i++)
		{
			scanf("%d%d",&x,&y);
			doors[x][y] = doors[y][x] = true;
		}

		for(int i=0; i <s; i++)
		{
			scanf("%d%d",&x,&y);
			control[x][y] = true;
		}

		state start, end;

		// start state
		start = createState(r, 1);
		start.lightOn = 1;

		// end state
		//end = createState(r, 1);
		//end.lightOn[0] = 1;

		end = createState(r, r);
		end.lightOn = (1<<(r-1));

		queue<pair<state,int> > qu;
		map<state, int> visited;
		map<state, state> parent;
		qu.push(make_pair(start,0));
		bool breakout = false;
		visited[start] = 0;

		while(!qu.empty() && !breakout)
		{
			pair<state,int> cur = qu.front();
			qu.pop();

			if(cur.first == end)
				break;

			// try all door states
			for(int i = 1; i<=r && !breakout; i++)
			{
				if(cur.first.roomNumber!=i && doors[cur.first.roomNumber][i] && getIth(cur.first.lightOn,i-1))
				{
					state newState = createState(r, i);
					newState.lightOn = cur.first.lightOn;

					if(visited.find(newState) == visited.end())
					{	
						parent[newState] = cur.first;
						visited[newState] =  cur.second+1;
						qu.push(make_pair(newState, cur.second+1));
					}
				}
			}

			// try all switch states
			for(int i = 1; i<=r && !breakout; i++)
			{
				if(cur.first.roomNumber!=i && control[cur.first.roomNumber][i])
				{
					state newState = createState(r, cur.first.roomNumber);
					newState.lightOn = cur.first.lightOn;

					// flipping the switch
					newState.lightOn = fiddleIth(newState.lightOn, i-1);

					if(visited.find(newState)== visited.end())
					{
						parent[newState] = cur.first;
						visited[newState] =  cur.second+1;
						qu.push(make_pair(newState, cur.second+1));
					}
				}
			}
		}
		printf("Villa #%d\n",villa++);
		if(visited.find(end) == visited.end())
		{
			printf("The problem cannot be solved.\n");
		}
		else
		{
			printf("The problem can be solved in %d steps:\n", visited[end]);
			PrintPath(parent, start, end);
		}

		printf("\n");
	}
	return 0;
}