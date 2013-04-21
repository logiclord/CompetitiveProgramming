#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<vector>
#include<map>
#include<cmath>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000

int getX(pair<char, char> card)
{
    //printf("\n%c%c\n",card.first,card.second);
	int val = card.first - '0';
	if(val >= 2 && val <= 9)
	{
		return val;
	}
	return 10;
}

int main()
{
	int k=1, num=0;
	scanf("%d",&num);
	while(num--)
	{
		pair<char,char> deck[52];
        char card[2];
		for(int i=0; i<52; i++)
		{
		    cout<<endl<<k<<"\t"<<num<<endl;
		    cin>>card;
			//scanf("%s",card);
			cout<<endl<<k<<"\t"<<num<<endl;
            deck[i].first = card[0];
            deck[i].second = card[1];
		}
		int index = 51-25;
		int y = 0;
		for(int i=0; i<3; i++)
		{
			int x = getX(deck[index]);
			y += x;
            //cout<<"DGEGE  "<<index;
			index = index - 1 - (10 - x);
			//cout<<"DGEGE  "<<index;
		}
		y--;
		//cout<<y<<"\t"<<index<<endl;
		printf("Case %d: ",k);
		if(y <= index)
		{
			printf("%c%c",deck[y].first,deck[y].second);
		}
		else
		{
			y = y - index + 27 - 1;
			printf("%c%c",deck[y].first,deck[y].second);
		}
		k++;
		printf("\n");
	}
	return 0;
}
