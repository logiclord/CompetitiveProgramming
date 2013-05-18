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
#include<cstring>

using namespace std;

int main()
{
	int trueExp = 0;
	string str;
	while(cin>>str)
	{
		stringstream sst(str);
		char op;
		int a,b,c;
		sst>>a>>op>>b;
		if(op == '-')
		{
			c = a-b;
		}
		else
		{
			c = a+b;
		}
		char c_real[5];
		sst>>op>>c_real;

		if(c_real[0]!='?' && atoi(c_real)==c)
		{
			trueExp++;
		}
	}
	printf("%d\n",trueExp);
	return 0;
}
