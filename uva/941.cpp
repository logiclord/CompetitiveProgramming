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
	long long int fact[21];
	fact[0] = 1;
	fact[1] = 1;
	for(int i=2;i<=20;i++)
	{
		fact[i]  = fact[i-1]*i;
	}
	int n;
	scanf("%d",&n);
	while(n--)
	{ 
		long long int num;
		bool picked[21] = {0};
		string line;
		cin>>line>>num;
		sort(line.begin(), line.end());
		int size = line.length();

		while(num>0 && size>=0)
		{
			int choice = num/fact[size-1];
			num = num%fact[size-1];
			size--;

			int counter = 0, k;

			for(k = 0; k<line.size(); k++)
			{
				if(picked[k] == false)
				{
					counter++;
					if(counter == choice+1)
					{

						choice = k;
						break;
					}
				}
			}

			if(k==line.size())
				break;

			//cout<<line[choice];
			picked[choice] = true;
		}
		for(int k = 0; k<line.size(); k++)
		{
			if(picked[k] == false)
			{
				cout<<line[k];
			}
		}
		cout<<endl;
	}
	return 0;
}
