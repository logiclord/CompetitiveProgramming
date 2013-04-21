#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <set>
#include <vector>
#include<map>
#include<cstdio>
#include<stack>
#include<cstring>
#include<climits>
#include<cmath>
#include<queue>

using namespace std;

int parent[1001];

void preSet(int x)
{
	for(int i=0;i<=x;i++)
	{
		parent[i] = i;
	}
}

int findSet(int x)
{
	return (parent[x]==x ? x : (parent[x]=findSet(parent[x])));
}

bool isSameSet(int x, int y)
{
	return findSet(x) == findSet(y);
}

void unionSet(int x, int y)
{
	parent[findSet(x)] = findSet(y);
}
