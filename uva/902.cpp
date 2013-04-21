#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <set>
#include <vector>
#include<map>
#include<cstdio>
#include<stack>
#include<cstring>
#include<climits>
#include<cmath>
#include<queue>
#include<string>

using namespace std;

int main()
{
	int n;
	string s;
	while(cin>>n>>s)
	{
		map<string, int> hash;
		string mostf = "";
		int mf = 0;
		int len = s.length();
		for(int i=0;i< len-n; i++)
		{
			string tmp = s.substr(i,n); 
			hash[tmp]++;
			if(hash[tmp] > mf)
			{
				mostf = tmp;
				mf = hash[tmp];
			}
		}
		cout<<mostf<<endl;
	}

	//system("pause");
	return 0;
}


