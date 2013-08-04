#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;



int getPoints(int x)
{
	switch(x)
	{
	case 3:
	case 4: return 1;
	case 5: return 2;
	case 6: return 3;
	case 7: return 5;
	default: return 11;
	}
}

bool findPattern(char *pattern, int hash[],  char data[10][10], int row, int col)
{
	if(pattern[0] == '\0')
		return true;
	int directionX[] = {1, 1, -1, -1, 0, 1, -1,  0};
	int directionY[] = {1,-1,  1, -1, 1, 0,  0, -1};

	bool ret = false;
	for(int i=0; i<8 && !ret; i++)
	{
		int x = row + directionX[i];
		int y = col + directionY[i];
		if(x>=0 && x<4 && y>=0 && y<4 && hash[x*10 + y] == 0 && data[x][y] == pattern[0])
		{
			hash[x*10 + y] = 1;
			ret = findPattern(pattern+1, hash, data, x, y);
			hash[x*10 + y] = 0;
		}
	}
	return ret;
}

int main()
{
	int testcases;
	scanf("%d", &testcases);
	for(int t=1; t <= testcases ; t++)
	{
		int k;
		char data[10][10];
		// This questions seems to have some problem with spacing that's why cin
		for(int i=0; i<4; i++)
		{
			cin>>data[i];
		}

		scanf("%d", &k);
		char pattern[20];
		int sum = 0;
		for(int i=0 ; i< k; i++)
		{
			bool getOut = false;
			cin>>pattern;
			for(int i=0; i<4 && !getOut; i++)
			{
				for(int j=0; j<4 && !getOut; j++)
				{
					if(pattern[0] == data[i][j])
					{
						int hash[50] = {0};
						hash[i*10  + j] = 1;
						if(findPattern(pattern+1, hash, data, i, j))
						{
							sum += getPoints(strlen(pattern));
							getOut = true;
						}
					}
				}
			}
		}
		printf("Score for Boggle game #%d: %d\n", t, sum);
	}
	return 0;
}
