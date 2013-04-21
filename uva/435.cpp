#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int data[21];
int dataHash[21];
int requiredSum=0;
int compare (const void * a, const void * b)
{
    return ( -*(int*)a + *(int*)b );
}

void makeSum(int sum, int n, int selected[], int m, int index)
{
    //cout<<"- "<<sum<<" "<<index<<" "<<n<<"\n";
    /*
    for(int i=0;index==m && i<n; i++)
    {
        cout<<data[selected[i]]<<" ";
    }
    cout<<endl;
    */
    if(index == m && sum>=requiredSum)
    {
        for(int i=0; i<n; i++)
        {
            if(sum-data[selected[i]] < requiredSum)
            {
                dataHash[selected[i]]++;
            }
        }
    }
    else if(index<m)
    {
        makeSum(sum,n,selected,m, index+1);
        selected[n] = index;
        makeSum(sum+data[index],n+1,selected,m, index+1);
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int p;
        int sum = 0;
        int selected[21];
        scanf("%d",&p);
        for(int i=0; i<p; i++)
        {
            scanf("%d",&data[i]);
            sum += data[i];
            dataHash[i] = 0;
        }
        //qsort (data, p, sizeof(int), compare);
        requiredSum = sum/2+1;
        makeSum(0,0, selected, p,0);
        for(int i=0; i<p; i++)
        {
            printf("party %d has power index %d\n",i+1,dataHash[i]);
        }
        printf("\n");
    }
    return 0;
}
