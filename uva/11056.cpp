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
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		vector<pair<int, pair<string, string> > > racers;
		for(int i=0; i<n; i++)
		{
			string name, temp;
			int min, sec, ms;
			cin >> name >> temp >> min >> temp >> sec >> temp >> ms >> temp;
			int lapTime = min*1000000  + sec*1000 + ms;
			string name2 = name;
			for(int k=0; k<name2.length(); k++)
			{
				if(islower(name2[k]))
				{
					name2[k] = toupper(name2[k]);
				}
			}
			racers.push_back(make_pair(lapTime, make_pair(name2, name)));
		}
		sort(racers.begin(), racers.end());
		int cases = 0;
		
		for (int i = 0; i < n; ++i){
			if (i % 2 == 0)
				printf("Row %d\n", ++cases);
			cout << racers[i].second.second << endl;
		}
		printf("\n");
	}
	return 0;
}
