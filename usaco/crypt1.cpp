/*
ID: gaurav91
PROG: crypt1
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

int main()
{
    ofstream off("crypt1.out");
    ifstream iff("crypt1.in");
    int n;
    int arr[20];
    bool data[20] = {false};
    set<pair<int,int> > st;
    iff>>n;
    for(int i=0; i<n; i++)
    {
        iff>>arr[i];
        data[arr[i]]= true;
    }

    for(int i=0; i<n; i++)
    {
        if(arr[i]>0)
            for(int j=0; j<n; j++)
            {
                for(int k=0; k<n; k++)
                {
                    int number = arr[i]*100 + arr[j]*10 + arr[k];
                    for(int l=0; l<n; l++)
                    {
                        if(arr[l]<=0)
                            continue;

                        int res = number * arr[l];
                        int ones = res%10;
                        int tens = (res%100)/10;
                        int hund = (res%1000)/100;
                       // off<<number<<"\t"<<res<<"\t"<<ones<<"\t"<<tens<<"\t"<<hund<<"\n";
                        if(res<1000 && data[ones] && data[tens] && data[hund])
                            for(int m=0; m<n; m++)
                            {
                                int res2 = number * arr[m];
                              //  off<<" in "<<arr[l]*10 + arr[m]<<"\n";
                                ones = res2%10;
                                tens = (res2%100)/10;
                                hund = (res2%1000)/100;
                                if(res2<1000 && data[ones] && data[tens] && data[hund])
                                {
                                    int fin = number*(arr[l]*10 + arr[m]);
                                    ones = fin%10;
                                    tens = (fin%100)/10;
                                    hund = (fin%1000)/100;
                                    int thou = (fin%10000)/1000;
                                   // off<<"    inner "<<fin<<"\t"<<ones<<"\t"<<tens<<"\t"<<hund<< "\t"<<thou<<"\n";
                                    if(fin<10000 && data[ones] && data[tens] && data[hund] && data[thou])
                                    {
                                        st.insert(pair<int,int>(number,arr[l]*10 + arr[m]));
                                    }
                                }
                            }
                    }
                }
            }
    }

    off<<st.size()<<"\n";

    return 0;
}
