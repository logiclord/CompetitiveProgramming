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

int main()
{
	vector<string> data;
	data.push_back("qaz");
	data.push_back("wsx");
	data.push_back("edc");
	data.push_back("rfvtgb");
	data.push_back(" ");
	data.push_back(" ");
	data.push_back("yhnujm");
	data.push_back("ik,");
	data.push_back("ol.");
	data.push_back("p;/");

	int n,m;
	while(cin>>n>>m)
	{
		int tmp;
		set<char> possible;
		set<int> broken;
		set<string> result;

		for(int i=0; i<n; i++)
		{
			cin>>tmp;
			broken.insert(tmp);
		}

		for(int i=0; i<10; i++)
		{
			if(broken.find(i+1)==broken.end())
			{
				for(string::iterator it=data[i].begin(); it!=data[i].end(); it++)
				{
					possible.insert(*it);
				}
			}
		}

		char input[100];
		int maxl = 0, maxnum = 0;
		for(int i=0; i<m; i++)
		{
			getchar();
			scanf("%s", input);
			bool isValid = true;
			for(int k=0;isValid && input[k]; k++)
			{
				if(possible.find(input[k])==possible.end())
				{
					isValid = false;
					break;
				}
			}
			string str(input);
			if(isValid && maxl <= str.length())
			{
				if(maxl < str.length())
				{
					maxl = str.length();
					maxnum = 0;
				}
				maxnum++;
				result.insert(str);
			}
		}

		maxnum = 0;
		for(set<string>::iterator it = result.begin(); it!=result.end(); it++)
		{
			if(it->length()==maxl)
				maxnum++;
		}
		cout<<maxnum<<endl;
		for(set<string>::iterator it = result.begin(); it!=result.end(); it++)
		{
			if(it->length()==maxl)
				cout<<*it<<endl;
		}
	}
	return 0;
}
