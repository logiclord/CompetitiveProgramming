#include<set>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<cstring>
#include<cctype>
#include<string>
#include<map>
#include<sstream>
using namespace std;

bool ARTICLE(string cur)
{
	return (cur=="a" || cur=="the");
}

bool NOUN(string cur)
{
	return (cur == "tom" || cur=="jerry" || cur=="goofy" || cur=="mickey" ||  cur=="jimmy" || cur=="dog" || cur=="cat" || cur=="mouse");
}

bool VERB(string cur)
{
	return (cur == "hate" || cur == "love"  || cur == "know" || cur=="like" || (*cur.rbegin() == 's' && VERB(cur.substr(0, cur.length()-1))));
}

bool ACTOR(vector<string> &data, int i, int j)
{
	if(i==j)
	{
		return NOUN(data[i]);
	}
	else if(i+1==j)
	{
		return (ARTICLE(data[i]) && NOUN(data[j]));
	}

	return false;
}

bool ACTIVE_LIST(vector<string> &data, int i, int j)
{
	for(int k=i+1; k<j; k++)
	{
		if(data[k]=="and" && ACTOR(data,k+1,j) && ACTIVE_LIST(data,i,k-1))
		{
			return true;
		}
	}
	return ACTOR(data,i,j);
}

bool ACTION(vector<string> &data, int i, int j)
{
	for(int k=i+1; k<j; k++)
	{
		if(VERB(data[k]) && ACTIVE_LIST(data,k+1,j) && ACTIVE_LIST(data,i,k-1))
		{
			return true;
		}
	}

	return 	ACTIVE_LIST(data,i,j);
}

bool STATEMENT(vector<string> &data, int i, int j)
{
	for(int k=i+1; k<j; k++)
	{
		if(data[k]=="," && ACTION(data,k+1,j) && STATEMENT(data,i,k-1))
		{
			return true;
		}
	}
	return ACTION(data,i,j);
}

int main()
{
	string line;
	while(!cin.eof() && getline(cin,line,'\n'))
	{
		bool valid = true;
		/*
		for(int i=0; i<line.length()-1;i++)
		{
			if(line[i]==line[i+1] && line[i]== ' ')
			{
				valid = false;
				break;
			}
		}*/
		string cur;
		stringstream sst(line);
		vector<string> data;
		while(valid && getline(sst,cur,' '))
		{
			data.push_back(cur);
		}
		if(valid && STATEMENT(data, 0, data.size()-1))
		{
			printf("YES I WILL\n");
		}
		else
		{
			printf("NO I WON%cT\n",39);
		}
	}
	return 0;
}
