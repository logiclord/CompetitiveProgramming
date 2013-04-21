#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<vector>
#include<map>
using namespace std;

#define INF 1000000000
typedef long long ll; 
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

struct cmp_str
{
   bool operator()(char const *a, char const *b)
   {
      return std::strcmp(a, b) < 0;
   }
};

int main()
{
	map<string, int>  hash;
	int n;
	char b[200], a[50];
	scanf("%d",&n);
	while(n--)
	{	
		scanf("%s%[^\n]",a,b);
		string t(a);
		hash[t] = hash[t] + 1;
	}
	for(map<string, int>::iterator it = hash.begin(); it != hash.end(); it++)
	{
		printf("%s %d\n",it->first.c_str(),it->second);
	}
	return 0;
}
