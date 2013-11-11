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

#define MAX_BOLTS 500
#define MAX_NUTS  500

/* global copy of the input data */
int nuts,bolts;
int fits[MAX_BOLTS][MAX_NUTS];

void read_input_data(void){
	int n,b;

	scanf("%d%d",&bolts,&nuts);
	for(b=0;b<bolts;b++){
		for(n=0;n<nuts;n++){
			scanf("%d",&fits[b][n]);
		}
	}
}

/* data used to match nuts with bolts */
int nut_owner[MAX_NUTS];


void init_match(void){
	int n;
	for(n=0;n<nuts;n++) nut_owner[n]=-1;
}

int AlternatePath(bool visited[], int curLefts)
{
	if(!visited[curLefts])
	{
		visited[curLefts] = true;
		for(int i=0; i<nuts; i++)
		{
			if( fits[curLefts][i] && (nut_owner[i]==-1 || AlternatePath(visited, nut_owner[i])))
			{
				nut_owner[i] = curLefts;
				return 1;
			}
		}
	}
	return 0;
}

int main(){
	int cases,caseno;

	scanf("%d",&cases);
	for(caseno=1;caseno<=cases;caseno++){
		read_input_data();
		init_match();
		int maxmatch = 0;
		for(int i=0; i<bolts; i++)
		{
			bool visible[MAX_BOLTS] = {false};
			maxmatch += AlternatePath(visible, i);
		}
		printf("Case %d: ",caseno);
		printf("a maximum of %d nuts and bolts ",maxmatch);
		printf("can be fitted together\n");
	}

	return 0;
}