#include<set>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<cstring>
#include<cctype>
#include<string>
#include<map>

using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	map<string, int> dictionary;
	string str;
	while(n--)
	{
		cin>>str;
		dictionary[str] = n;
	}
	scanf("%d",&n);
	while(n--)
	{
		cin>>str;
		if(dictionary.find(str)!=dictionary.end())
		{
			cout<<str<<" is correct";
		}
		else
		{
			int lastMatch = -1;
			string correctedWord = "";
			int size = str.length();

			// replacing each character
			for(int i=0; i < size; i++)
			{
				char original = str[i];
				for(char change = 'a'; change <= 'z'; change++)
				{
					str[i] = change;
					if(dictionary.find(str)!=dictionary.end() && dictionary[str]> lastMatch)
					{
						lastMatch = dictionary[str];
						correctedWord = str;
					}
				}
				str[i] = original;
			}

			// inserting character
			for(int i=0; i <= size; i++)
			{
				for(char change = 'a'; change <= 'z'; change++)
				{
					string temp = str;
					temp.insert(i, 1, change);
					if(dictionary.find(temp)!=dictionary.end() && dictionary[temp]> lastMatch)
					{
						lastMatch = dictionary[temp];
						correctedWord = temp;
					}
				}
			}

			// deleteing character
			for(int i=0; i < size; i++)
			{
				string temp = str;
				temp.erase(i, 1);
				if(dictionary.find(temp)!=dictionary.end() && dictionary[temp] > lastMatch)
				{
					lastMatch = dictionary[temp];
					correctedWord = temp;
				}
			}

			// swapping characters
			for(int i=0; i < size-1; i++)
			{
				swap(str[i],str[i+1]);
				if(dictionary.find(str)!=dictionary.end() && dictionary[str] > lastMatch)
				{
					lastMatch = dictionary[str];
					correctedWord = str;
				}
				swap(str[i],str[i+1]);
			}

			if(lastMatch==-1)
			{
				cout<<str<<" is unknown";
			}
			else
			{
				cout<<str<<" is a misspelling of "<<correctedWord;
			}
		}
		printf("\n");
	}
	return 0;
}
