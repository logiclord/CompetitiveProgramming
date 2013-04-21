#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<vector>
#include<map>
#include<cmath>
#include<cstdlib>

using namespace std;

typedef long long ll; 
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000



int main()
{
	int n;
	scanf("%d",&n);
	bool blank = false;
	while(n--)
	{
		int input[101][52];
		int initial[52]; //{1,2,3,4,5,6,7,8,9,10,11,12,0,14,15,16,17,18,19,20,21,22,23,24,25,13,
				//	27,28,29,30,31,32,33,34,35,36,37,38,26,40,41,42,43,44,45,46,47,48,49,50,51,39};
		for(int i=0;i<52;i++)
			initial[i] = i;
		//int seen[101];
		int s;
		scanf("%d",&s);
		for(int i=0;i<s;i++)
		{
			for(int j=0;j<52;j++)
				scanf("%d",&input[i][j]);
		}
	//	getchar();	
		char input2 [50];
		cin.ignore();
	        while ( cin.getline(input2,40) && strlen (input2) ) 
		{
			//	cout<<tmp<<"\t"<<tmp.empty()<<endl;
			int t = atoi(input2);
			int  temp[52];
			//	cout<<"  FFF "<<t<<endl;
			t--;	
			for(int j=0; j<52;j++)
			{
				//	cout<<t<<" "<<j<<" "<<initial[input[t][j]-1]<<endl;
				temp[j] = initial[input[t][j]-1];
			}
			for(int j=0; j<52;j++)
			{
				initial[j] = temp[j];
			}	
			//	cin.ignore();
		}

		if(blank)
			printf("\n");
		blank = true;

		for(int i=0; i<52; i++)
		{
			//cout<<initial[i]<<"\t";
			if((initial[i] + 1)%13 == 0)
				printf("Ace");
			else if((initial[i]+2)%13 == 0)
				printf("King");
			else if((initial[i] + 3)%13 == 0)
				printf("Queen");
			else if((initial[i] + 4)%13 == 0)
				printf("Jack");
			else 
				printf("%d",(initial[i] + 2)%13);

			if(initial[i]>=0 && initial[i]<=12) printf(" of Clubs\n");
			if(initial[i]>=13 && initial[i]<=25) printf(" of Diamonds\n");
			if(initial[i]>=26 && initial[i]<=38) printf(" of Hearts\n");
			if(initial[i]>=39 && initial[i]<=52) printf(" of Spades\n");
		}
	}
	return 0;
}




