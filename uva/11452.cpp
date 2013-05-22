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
	int n;
	scanf("%d",&n);	
	while(n--)
	{
		char data[2002];
		getchar();
		scanf("%[^\n]",data);
		int len = strlen(data);
		int last = (len-1)/2;
		int width;
		for(width=(len/3)+1; width<=last; width++)
		{
			bool isValid = true;
			for(int i=0;isValid && i<width; i++)
			{
				if(i+2*width < len && data[i+2*width]!=data[i])
				{
					isValid = false;
				}
				if(data[i]!=data[i+width])
				{
					isValid = false;
				}
			}
			if(isValid)
				break;
		}

		int start = len-2*width;
		for(int i=0; i<8; i++)
		{
			printf("%c", data[start]);
			start = (start+1)%width;
		}
		printf("...\n");
	}
	return 0;
}
