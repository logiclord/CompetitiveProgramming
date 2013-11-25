#include<set>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<cstring>
#include<cctype>
#include<string>
#include<map>
#include<sstream>
using namespace std;


class BigNum
{
public:
	int size;
	char data[201];
	BigNum()
	{
		size = 0;
		data[0] = '\0';
	}
	BigNum operator+(const BigNum &op) const
	{
		BigNum answer;
		int n = 0, sum = 0, m = 0, carry = 0;

		while(n<op.size || m<this->size)
		{
			if(n<op.size && m<this->size)
			{
				sum = carry + this->data[m++] - '0' + op.data[n++] - '0';
			}
			else if(n<op.size)
			{
				sum = carry + op.data[n++] - '0';
			}
			else
			{
				sum = carry + this->data[m++] - '0';
			}
			answer.data[(answer.size)++] = sum%10 + '0';
			carry = sum/10;
		}
		if(carry > 0)
			answer.data[(answer.size)++] = carry + '0';
		answer.data[answer.size] = '\0';
		return answer;
	}
};




int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		BigNum addOp1, addOp2;
		cin>>addOp1.data;
		//strrev(addOp1.data);
		addOp1.size = strlen(addOp1.data);
		cin>>addOp2.data;
		//strrev(addOp2.data);
		addOp2.size = strlen(addOp2.data);

		BigNum answer = addOp1 + addOp2;
		bool valid = false;
		for(int i=0; i<answer.size ;i++)
		{
			if(answer.data[i] > '0')
				valid = true;

			if(valid)
			{
				cout<<answer.data[i];
			}
		}
		cout<<endl;
	}
}


