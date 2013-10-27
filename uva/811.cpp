// Adrian Dale
// 12/09/2012
// Solves online judge problem: 811 - The Fortified Forest
// 10590104 	811 	The Fortified Forest 	Accepted 	C++ 	0.240 	2012-09-11 12:55:19
// Accepted first try, ranked 136th
// Uses code from http://www.algorithmist.com/index.php/Monotone_Chain_Convex_Hull.cpp
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>
#include <assert.h>
#include<stack>
using namespace std;

struct Tree
{
	int x;
	int y;
	int v;
	int l;
	Tree(int ix, int iy, int iv, int il) : x(ix), y(iy), v(iv), l(il) {}
	Tree() : x(0), y(0), v(0), l(0) {}
};

int ForestNo;
vector<Tree> Forest;

typedef int coord_t;         // coordinate type
typedef long long coord2_t;  // must be big enough to hold 2*max(|coordinate|)^2

struct Point {
	coord_t x, y;

	bool operator <(const Point &p) const {
		return x < p.x || (x == p.x && y < p.y);
	}
};


coord2_t cross(const Point &O, const Point &A, const Point &B)
{
	return (A.x - O.x) * (coord2_t)(B.y - O.y) - (A.y - O.y) * (coord2_t)(B.x - O.x);
}

struct comp
{
	Point pivot;
	bool operator()(Point p1, Point p2)
	{
		int val = cross(pivot, p1, p2);
		if(val == 0)
			return hypot(p1.x - pivot.x, p1.y - pivot.y) < hypot(p2.x - pivot.x, p2.y - pivot.y);
		return val > 0;
	}
};


vector<Point> convex_hull(vector<Point> &P)
{
	if(P.size() <=1)
		return P;
	else if(P.size() <= 3)
	{
		P.push_back(P.front());
		return P;
	}
	else
	{
		int pivot = 0;
		comp compu;
		for(int i=0; i<P.size(); i++)
		{
			if(P[pivot].y > P[i].y || (P[pivot].y == P[i].y && P[pivot].x < P[i].x ))
			{
				pivot = i;
			}
		}
		swap(P[pivot], P[0]);
		compu.pivot = P[0];
		sort(P.begin() + 1, P.end(), compu);
		stack<Point> scan;
		scan.push(P.back());
		scan.push(P.front());
		Point prev, cur;
		int i=1;
		while(i<P.size())
		{
			cur = scan.top();
			scan.pop();
			prev = scan.top();
			scan.push(cur);
			if(cross(prev, cur, P[i])>=0)
			{
				scan.push(P[i++]);
			}
			else
			{
				scan.pop();
			}
		}

		vector<Point> answer;
		while(!scan.empty())
		{
			answer.push_back(scan.top());
			scan.pop();
		}
		return answer;
	}
}
//
////////////

// Calculate the perimeter of the forest, ignoring any tree with
// a 1 bit set in choppedTrees
// This uses the convex_hull code above, so we have some inefficient
// memory copying and passing, but I did it this way as I wanted to leave
// the convex_hull function untouched. (Save changing it to pass by reference)
double ForestPerimeter(int choppedTrees, int &choppedValue, int &fenceLength, int &treesChopped)
{
	// Fill pts with all of the unchopped trees
	vector<Point> pts;
	choppedValue = 0;
	fenceLength = 0;
	treesChopped = 0;
	for(unsigned int i=0; i<Forest.size(); ++i)
	{
		if (((choppedTrees >> i) & 1) == 0)
		{
			// Include tree
			Point pt;
			pt.x = Forest[i].x;
			pt.y = Forest[i].y;
			pts.push_back(pt);
		}
		else
		{
			// Tree has been chopped down, so add it to the
			// value of the chopped wood and the length of fence we can
			// make from it
			choppedValue += Forest[i].v;
			fenceLength += Forest[i].l;
			++treesChopped;
		}
	}

	// Get the points that are on the fence
	vector<Point> result = convex_hull(pts);

	// Calculate the perimeter - it's the sum of the lengths from each point to the next.
	// Nicely helped by the way our borrowed function returns the points.
	double perim = 0.0;
	if (result.size() < 2) // eg when all trees are chopped down
		return 0.0;

	for(unsigned int i=0; i<result.size()-1; ++i)
	{
		perim += sqrt( static_cast<double>((result[i+1].x - result[i].x)*(result[i+1].x - result[i].x) +
			(result[i+1].y - result[i].y)*(result[i+1].y - result[i].y)) );
	}

	return perim;
}

void solveForest()
{
	int bestTreesChopped = Forest.size() + 1;
	int bestChoppedValue = numeric_limits<int>::max();
	int bestFenceLength = numeric_limits<int>::max();
	int bestCombination = -1;
	double bestPerimeter = 0.0;

	// Try every possible combination of trees chopped
	// There are a maximum of 15 trees, which is only 65536 possible combinations.
	int maxcomb = static_cast<int>(pow(2.0, static_cast<double>(Forest.size())) );
	for(int chopped=0; chopped < maxcomb; ++chopped)
	{
		int choppedValue;
		int fenceLength;
		int treesChopped;

		double perimeter =  ForestPerimeter(chopped, choppedValue, fenceLength, treesChopped);

		// See if we've chopped enough trees to make a fence big enough
		if (perimeter <= fenceLength)
		{
			if (choppedValue < bestChoppedValue)
			{
				bestChoppedValue = choppedValue;
				bestFenceLength = fenceLength;
				bestCombination = chopped;
				bestPerimeter = perimeter;
				bestTreesChopped = treesChopped;
			}
			else if (choppedValue == bestChoppedValue)
			{
				// Tie-break
				if (treesChopped < bestTreesChopped)
				{
					bestTreesChopped = treesChopped;
					bestCombination = chopped;
					bestFenceLength = fenceLength;
					bestPerimeter = perimeter;
				}
			}
		}
	}

	cout << "Forest " << ForestNo << endl;

	// NB Spec doesn't say what to do if no perimeter is
	// possible.
	cout << "Cut these trees:";
	for(unsigned int i=0; i<Forest.size(); ++i)
	{
		if (((bestCombination >> i) & 1) == 1)
		{
			cout << " " << i+1;
		}
	}
	cout << endl;

	cout << "Extra wood: " << fixed << setprecision(2) 
		<< static_cast<double>(bestFenceLength) - bestPerimeter << endl;
}

int main()
{	
	ForestNo = 0;
	int NoOfTrees;
	while(cin>>NoOfTrees && NoOfTrees)
	{
		assert(NoOfTrees >= 2 && NoOfTrees <= 15);

		// So we get blank line between (but not after) test cases
		if (ForestNo != 0 )
			cout << endl;

		++ForestNo;
		Forest.clear();
		while(NoOfTrees-- > 0)
		{
			Tree newTree;
			cin >> newTree.x >> newTree.y >> newTree.v >> newTree.l;
			Forest.push_back( newTree );
		}
		solveForest();
	}
	return 0;
}