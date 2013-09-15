#include<iostream>
#include<vector>
using namespace std;

int main()
{
	char str1[100], str2[100];
	int len1, len2;
	bool firstTime = true;

	while(gets(str1) && gets(str2))
	{
		if(!firstTime)
			printf("\n");
		else
			firstTime = false;

		int data[100][100] = {0};
		int choice[100][100] = {0};

		len2 = strlen(str2);
		len1 = strlen(str1);

		for(int i=0; i<=len2; i++)
		{	
			data[0][i] = i;
			choice[0][i] = 2;
		}
		for(int i=0; i<=len1; i++)
		{
			data[i][0] = i;
			choice[i][0] = 1;
		}

		for(int i=1; i<=len1; i++)
		{
			for(int j=1; j<=len2; j++)
			{
				data[i][j] = min(data[i-1][j-1] + (str1[i-1]!=str2[j-1]), min(data[i-1][j], data[i][j-1]) + 1);
				if(data[i][j] == data[i-1][j]+1)
					choice[i][j] = 1;
				else if(data[i][j] == data[i][j-1]+1)
					choice[i][j] = 2;
				else
					choice[i][j] = 3;
			}
		}

		int i=len1, j=len2;
		vector<pair<const char *, pair<int,char> > > ops;

		while(i>0 || j>0)
		{
			if(choice[i][j]==1)
			{
				ops.push_back(make_pair("Delete", make_pair(i,str1[i-1])));
				i--;
			}
			else if(choice[i][j]==2)
			{
				ops.push_back(make_pair("Insert", make_pair(i+1,str2[j-1])));
				j--;
			}
			else if(choice[i][j] == 3 && str1[i-1]!=str2[j-1])
			{
				ops.push_back(make_pair("Replace", make_pair(i,str2[j-1])));
				i--;
				j--;
			}
			else
			{
				i--;
				j--;
			}
		}

		int count = 1, offset = 0;
		printf("%d\n", data[len1][len2]);
		for(vector<pair<const char *, pair<int,char> > >::reverse_iterator it = ops.rbegin(); it!=ops.rend(); it++)
		{
			printf("%d ", count++);
			if(it->first[0] == 'I')
			{
				printf("%s %d,%c", it->first, it->second.first + offset, it->second.second);
				offset++;
			}
			else if(it->first[0] == 'D')
			{
				printf("%s %d", it->first, it->second.first + offset);
				offset--;
			}
			else
			{
				printf("%s %d,%c", it->first, it->second.first + offset, it->second.second);
			}
			printf("\n");
		}
	}
	return 0;
}