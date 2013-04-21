#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<vector>
#include<map>
#include<string>
#include<cmath>
#include <algorithm> 
using namespace std;

typedef long long ll; 
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000

int nS=0, nD=0, nH=0, nC=0;

int AdditionalPoints(int n)
{
	if(n == 0 || n == 1)
		return 2;
	if(n == 2)
		return 1;
	return 0;
}

int SubtractPoints(vector<char>&v, int p)
{
	int tmp = 0;
	for(vector<char>::iterator it = v.begin(); it!=v.end(); it++)
	{
		if(*it == 'S' && nS <= p)
		{
			tmp--; 
		}
		else if(*it == 'C' && nC <= p)
		{
			tmp--;
		}
		else if(*it == 'D' && nD <= p)
		{
			tmp--;
		}
		else if(*it == 'H' && nH <= p)
		{
			tmp--;
		}
	}
	return tmp;
}

char maxs()
{
	if(nS>= max(max(nC,nH),nD))
	{
		return 'S';
	}
	else if(nH>= max(max(nC,nS),nD))
	{
		return 'H';
	}
	else if(nD>= max(max(nC,nH),nS))
	{
		return 'D';
	}
	else
	{
		return 'C';
	}
}

int main()
{
	char str[100];
	while(cin.getline(str,50,'\n'))
	{
		//cout<<str<<endl;
		nS=0, nD=0, nH=0, nC=0;
		vector<char> vk,vq,vj,va;
		int score = 0;
		for(int i=0; i<39; i=i+3)
		{
			if(str[i+1] == 'S')
			{
				nS++;
			}
			else if(str[i+1] == 'C')
			{
				nC++;
			}
			else if(str[i+1] == 'D')
			{
				nD++;
			}
			else
			{
				nH++;
			}
			if(str[i] == 'A')
			{
				score = score + 4;
				va.push_back(str[i+1]);
			}
			else if(str[i] == 'K')
			{
				vk.push_back(str[i+1]);
				score = score + 3;
			}
			else if(str[i] == 'Q')
			{	vq.push_back(str[i+1]);
				score += 2;
			}
			else if(str[i] == 'J')
			{	vj.push_back(str[i+1]);
				score++;
			}
			//cout<<str[i]<<str[i+1]<<"\t"<<score<<endl;
		}
		score = score + SubtractPoints(vk,0) + SubtractPoints(vq,1) + SubtractPoints(vj,2);
		int iAllStopped = 0;
		if( (find(va.begin(), va.end(), 'C') != va.end()) ||(nC >= 2 && find(vk.begin(), vk.end(), 'C') != vk.end()) || (nC >= 3 && find(vq.begin(), vq.end(), 'C') != vq.end()))
		{
			iAllStopped++;
		}
		if( (find(va.begin(), va.end(),'D') != va.end()) ||(nD >= 2 && find(vk.begin(), vk.end(), 'D') != vk.end()) || (nD >= 3 && find(vq.begin(), vq.end(),'D') != vq.end()))
		{
			iAllStopped++;
		}
		if( (find(va.begin(), va.end(),'H') != va.end()) ||(nH >= 2 && find(vk.begin(), vk.end(), 'H') != vk.end()) || (nH >= 3 && find(vq.begin(), vq.end(),'H') != vq.end()))
		{
			iAllStopped++;
		}
		if( (find(va.begin(), va.end(),'S') != va.end()) ||(nS >= 2 && find(vk.begin(), vk.end(), 'S') != vk.end()) || (nS >= 3 && find(vq.begin(), vq.end(),'S') != vq.end()))
		{
			iAllStopped++;
		}

		//cout<<iAllStopped<<endl;
		if(score >=16 && iAllStopped == 4)
		{
			printf("BID NO-TRUMP\n");
		}
		else
		{
			//cout<< score<<endl;
			score = score + AdditionalPoints(nH) + 	AdditionalPoints(nC) + AdditionalPoints(nD) + AdditionalPoints(nS);
			if(score < 14)
			{
				printf("PASS\n");
			}
			else
			{
				printf("BID %c\n", maxs());
			}
		}
	}
	return 0;
}
