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
#include<cstring>

using namespace std;
bool expression(char data[], int i, int j, int &val);
bool component(char data[], int i, int j, int &val);
bool factor(char data[], int i, int j, int &val);

// Using recursive descent parsing approach

bool isOperator(char op)
{
	return (op=='+' || op=='-' || op=='*' || op=='/' );
}

int calculateOperator(char op, int a, int b)
{
	switch (op)
	{
	case '+': return (a+b);
	case '-': return (a-b);
	case '*': return (a*b);
	case '/': return (a/b);
	}
	return -1;
}

bool factor(char data[], int i, int j, int &val)
{
	bool isNum = true;
	int temp = 0;
	for(int k=i;isNum && k<=j; k++)
	{
		if(!isdigit(data[k]))
		{
			isNum = false;
			break;
		}
		temp = temp*10 + (data[k]-'0');
	}
	if(isNum)
	{
		val = temp;
		return true;
	}
	if(data[i]=='(' && data[j]==')' && j-i>1 && expression(data,i+1,j-1,val))
	{
		return true;
	}
	return false;
}

bool component(char data[], int i, int j, int &val)
{
	if(factor(data,i,j,val))
	{
		return true;
	}
	else
	{
		int inParanthesis = 0;
		for(int k=i+1; k<j; k++)
		{
			inParanthesis = inParanthesis -  (data[k]==')') + (data[k]=='(');
			if(inParanthesis == 0 && isOperator(data[k]))
			{
				int val1, val2;
				if(factor(data,i,k-1,val1) && component(data,k+1,j,val2))
				{
					val = calculateOperator(data[k], val1, val2);
					return true;
				}
			}
		}
	}
	return false;
}

bool expression(char data[], int i, int j, int &val)
{
	if(component(data,i,j,val))
	{
		return true;
	}
	else
	{
		int inParanthesis = 0;
		for(int k=i+1; k<j; k++)
		{
			inParanthesis = inParanthesis -  (data[k]==')') + (data[k]=='(');
			if(inParanthesis == 0 && isOperator(data[k]))
			{
				int val1, val2;
				if(component(data,i,k-1,val1) && expression(data,k+1,j,val2))
				{
					val = calculateOperator(data[k], val1, val2);
					return true;
				}
			}
		}
	}
	return false;
}

int main()
{
	char data[500];
	int n;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%s",data);
		int val;
		if(expression(data, 0, strlen(data)-1, val))
		{
			printf("%d\n",val);
		}
		else
		{
			printf("ERROR\n");
		}
	}
	return 0;
}
