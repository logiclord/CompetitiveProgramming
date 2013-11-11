#include<iostream>
#include<algorithm>
#include<cstdio>
#include<map>
#include<vector>
#include<list>
#include<stack>
#include<string>
#include<sstream>
using namespace std;
#define INF 99999999


int main()
{
	int t;
	cin>>t;
	getchar();
	getchar();
	bool blank = false;
	string str;
	while(t--)
	{
		getline(cin, str);
		if(blank)
			printf("\n");
		blank = true;

		double dist = 0.0;
		int px, py, tx, ty;
		stringstream sst;
		sst.str(str);
		sst>>px>>py;
		while(getline(cin, str) && str[0]!='\0')
		{
			sst.clear();
			sst.str(str);
			sst>>px>>py>>tx>>ty;
			dist += 2*hypot(px-(double)tx, py - (double)ty);
		}

		double speed = 20.0*1000.0/3600.0;
		double time = dist/speed;
		int hr = time/3600;
		time -= hr*3600;
		int min = (time/60 + 0.5);
		if(min==60)
		{
			hr++;
			min = 0;
		}
		printf("%d:", hr);
		if(min < 10)
			printf("0%d\n",min);
		else
			printf("%d\n", min);
	}

	return 0;
}


