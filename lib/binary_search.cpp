
#include<iostream>
using namespace std;


int findFirstOccurence(int x, int arr[], int size)
{
	int lo = 0, hi = size-1, mid = lo;
	while(lo<hi)
	{
		mid = (lo + hi)/2;
		if(arr[mid] < x)
		{
			lo = mid + 1;
		}
		else if(arr[mid] > x)
		{
			hi = mid - 1;
		}
		else
		{
			if((mid==0 || arr[mid-1]!=x) && arr[mid] == x)
			{
				return mid;
			}
			else
			{
				hi = mid - 1;
			}
		}
	}
	return -1;
}

int findLastOccurence(int x, int arr[], int size)
{
	int lo = 0, hi = size-1, mid = lo;
	while(lo<hi)
	{
		mid = (lo + hi)/2;
		if(arr[mid] < x)
		{
			lo = mid + 1;
		}
		else if(arr[mid] > x)
		{
			hi = mid - 1;
		}
		else
		{
			if((mid==size-1 || arr[mid+1]!=x) && arr[mid] == x)
			{
				return mid;
			}
			else
			{
				lo = mid + 1;
			}
		}
	}
	return -1;
}


int findJustSmaller(int x, int arr[], int size)
{
	int lo = 0, hi = size-1, mid = lo;
	while(lo<hi)
	{
		mid = (lo + hi+ 1)/2;
		if(arr[mid] >= x)
		{
			hi= mid - 1;
		}
		else
		{
			lo = mid;
		}
	}
	return lo;
}

int findJustLarger(int x, int arr[], int size)
{
	int lo = 0, hi = size-1, mid = lo;
	while(lo<hi)
	{
		mid = (lo + hi)/2;
		if(arr[mid] > x)
		{
			hi= mid;
		}
		else
		{
			lo = mid+1;
		}
	}
	return lo;
}

int main()
{
	int arry[] = {1,2,45};
	cout<<findJustSmaller(32,arry, sizeof(arry)/sizeof(int));
	return 0;
}