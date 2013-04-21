#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<vector>
using namespace std;

typedef long long ll; 
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000

void generateSubsets(int A[], int n, int num, int selected[], int m)
{
//	cout<<m<<endl;
	if(n == num)
	{
		if(m == 0)
		{
			cout<<"NULL";	
		}
		else
		{
			for(int i=0; i<m; i++)
			{
				cout<<selected[i]<<" ";
			}
		}
		cout<<endl;
	}
	else
	{
		generateSubsets(A, n+1, num, selected, m);
		selected[m] = A[n];
		generateSubsets(A, n+1, num, selected, m+1);
	}
}

int main()
{
	int A[] = {1,2,3};
	int selected[] = {0,0,0};
	generateSubsets(A, 0, 3, selected, 0);
	return 0;
}
