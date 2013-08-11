#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

/*
All major sorting algorithms
*/


void bubbleSort(int arr[], int size)
{
	for(int h=0 ;h<size-1; h++)
	{
		for(int k=0;k < (size-h-1); k++)
		{
			if(arr[k] > arr[k+1])
			{
				swap(arr[k], arr[k+1]);
			}
		}
	}
}

void selectionSort(int arr[], int size)
{
	for(int i=0; i<size-1; i++)
	{
		int mini  = INT_MAX, mj;
		for(int j=i; j<size; j++)
		{
			if(mini>arr[j])
			{
				mj = j;
				mini = arr[j];
			}
		}
		swap(arr[i], arr[mj]);
	}
}


void insertionSort(int arr[], int size)
{
	for(int i = 1; i< size; i++)
	{
		int pos = i, val = arr[i];
		while(pos > 0 && arr[pos-1]>val)
		{
			arr[pos]  = arr[pos-1];
			pos--;
		}
		arr[pos] = val;
	}
}

void mergeWrapper(int arr[], int i, int j)
{
	if(i<j)
	{
		int mid = (i+j)/2;
		mergeWrapper(arr, i, mid);
		mergeWrapper(arr, mid+1, j);
		int *data = new int[j-i+1];
		int p = i, q = mid+1, k = 0;
		while(p<=mid || q<=j)
		{
			if(p<=mid && q<=j)
			{
				if(arr[p] < arr[q])
					data[k++] = arr[p++];
				else
					data[k++] = arr[q++];
			}
			else if(p<=mid)
			{
				data[k++] = arr[p++];
			}
			else
			{
				data[k++] = arr[q++];
			}
		}
		for(int p = 0; p<k; p++)
		{
			arr[i+p] = data[p];
		}
		delete[] data;
	}
}

void mergeSort(int arr[], int size)
{
	mergeWrapper(arr,0, size-1);
}

void merge(int arr[], int i, int j, int k, int l)
{
	int m = i, n =l;
	int p  = 0;
	int *data = new int[l-i+1];
	while(i<=j || k<=l)
	{
		if(i<=j && k<=l)
		{
			if(arr[i] < arr[k])
			{
				data[p++] = arr[i++];
			}
			else
			{
				data[p++] = arr[k++];
			}
		}
		else if(i<=j)
		{
			data[p++] = arr[i++];
		}
		else
		{
			data[p++] = arr[k++];
		}
	}
	for(int i=m; i<=n ;i++)
	{
		arr[i] = data[i-m];
	}
	delete []data;
}

void mergeSortBottomUp(int arr[], int size)
{
	for(int exp = 1 ; exp <= size; exp = exp<<1)
	{
		for(int start=0; start + exp <= size-1; start = start + 2*exp)
		{
			merge(arr, start, start+exp-1, start+exp, min(start+2*exp-1, size-1));
		}
	}
}

int getPivot(int arr[], int i, int j)
{
	int pivot = arr[i], p = i;
	swap(arr[i], arr[j]);
	for(int k=i; k<j; k++)
	{
		if(arr[k]<=pivot)
			swap(arr[k], arr[p++]);
	}
	swap(arr[j], arr[p]);
	return p;
}

int getPivotMod(int arr[], int i, int j)
{
	int beg = i, end =j;
	int pivot = arr[i];
	while(beg<end)
	{
		while(arr[beg]<=pivot && beg<=j)
		{
			beg++;
		}
		while(arr[end]>pivot && end>=i)
		{
			end--;
		}
		if(beg<end)
		{
			swap(arr[beg], arr[end]);
		}
	}
	swap(arr[i], arr[end]);
	return end;
}


void quickSortWrapper(int arr[], int i, int j)
{
	if(i<j)
	{
		int k = getPivotMod(arr, i, j);
		quickSortWrapper(arr, i, k-1);
		quickSortWrapper(arr, k+1, j);
	}
}

void quickSort(int arr[], int size)
{
	quickSortWrapper(arr, 0, size-1);
}

void quickSortIterative(int arr[], int size)
{
	stack<pair<int,int> >st;
	st.push(make_pair(0, size-1));
	while(!st.empty())
	{
		pair<int,int> range = st.top();
		st.pop();
		int pivot = getPivot(arr, range.first, range.second);
		if(range.first<pivot-1)
			st.push(make_pair(range.first,pivot-1));
		if(pivot+1 < range.second)
			st.push(make_pair(pivot+1, range.second));
	}
}

void heapify(int arr[], int size, int origin)
{
	int left = 2*origin + 1;
	int right = 2*origin + 2;
	if(right < size && (arr[origin] < arr[left] ||  arr[origin] < arr[right]))
	{
		int point = left;
		if(arr[right] > arr[left])
			point = right;
		swap(arr[origin], arr[point]);
		heapify(arr, size, point);
	}
	else if(left < size && arr[origin] < arr[left])
	{
		swap(arr[origin], arr[left]);
		heapify(arr, size, left);
	}
}

void heapSort(int arr[], int size)
{
	// converting to max heap
	for(int k = (size-2)/2; k>=0; k--)
	{
		heapify(arr, size, k);
	}

	for(int k=size-1; k>0; k--)
	{
		swap(arr[k], arr[0]);
		heapify(arr, k, 0);
	}
}


int splitRadix(int arr[], int beg, int end, int radix)
{
	int  pivot = (1<<radix);
	int p = beg;
	for(int i = beg; i<=end; i++)
	{
		if(arr[i]<pivot)
		{
			swap(arr[i], arr[p++]);
		}
	}
	return (p-1);
}

void radixExchangeSortWrapper(int arr[], int beg, int end, int radix)
{
	if(beg < end && radix>=0)
	{
		int p = splitRadix(arr, beg, end, radix);
		radixExchangeSortWrapper(arr, beg, p, radix-1);
		radixExchangeSortWrapper(arr, p+1, end, radix-1);
	}
}

int getHSB(int arr[], int beg, int end)
{
	int m = INT_MIN, hsb = 0;

	for(int i=beg; i<=end; i++)
	{
		m = max(m, arr[i]);
	}
	while(m>0)
	{
		m = m>>1;
		hsb++;
	}
	return hsb;
}

void radixExchangeSort(int arr[], int size)
{
	int p = 0;
	for(int i=0; i<size; i++)
	{
		if(arr[i]<0)
		{
			swap(arr[i], arr[p]);
			arr[p++] *= -1;
		}
	}

	radixExchangeSortWrapper(arr, 0, p-1, getHSB(arr, 0, p-1));
	radixExchangeSortWrapper(arr, p, size-1, getHSB(arr, p, size-1));

	// restoring negative numbers
	for(int i=0, j=p-1; i<=j;i++, j--)
	{
		if(i!=j)
		{
			swap(arr[i], arr[j]);
			arr[i] *= -1;
		}
		arr[j] *= -1;
	}
}


void radixStraightSortWrapper(int arr[], int beg, int end)
{
	// radix sort in base 10
	// using counting sort
	int maxi = INT_MAX;
	for(int i=beg; i<=end; i++)
	{
		maxi = max(maxi, arr[i]);
	}

	int exp = 1;
	int * data = new int[end - beg + 1];
	while(maxi <  exp)
	{
		int hash[10] = {0};
		// counting sort
		for(int i=beg; i<=end; i++)
		{
			hash[arr[i]/exp %10]++;
		}
		for(int i=0; i<10; i++)
		{
			arr[i] += arr[i-1];
		}
		for(int i=end; i>=beg; i--)
		{
			data[hash[arr[i]/exp %10]--] = arr[i];
		}
		for(int i=beg; i<=end; i++)
		{
			arr[i] = data[i-beg];
		}
		exp *= 10;
	}
	delete [] data;
}

void radixStraightSort(int arr[], int size)
{
	int p = 0;
	for(int i=0; i<size; i++)
	{
		if(arr[i]<0)
		{
			swap(arr[i], arr[p]);
			arr[p++] *= -1;
		}
	}

	radixStraightSortWrapper(arr, 0, p-1);
	radixStraightSortWrapper(arr, p, size-1);

	// restoring negative numbers
	for(int i=0, j=p-1; i<=j;i++, j--)
	{
		if(i!=j)
		{
			swap(arr[i], arr[j]);
			arr[i] *= -1;
		}
		arr[j] *= -1;
	}
}


int main()
{
	int arry[] = {100,2,45, 53 ,567,39983, 5, -4, -445, 4, 39, 94, -3434, 23723, 35,234, 121, -244, 982958258};
	int size =  sizeof(arry)/sizeof(int);
	mergeSortBottomUp(arry, size);
	for(int i=0; i<size; i++)
	{
		cout<<arry[i]<<endl;
	}
	return 0;
}