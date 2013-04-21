#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <stack>

using namespace std;

int opVal(char c)
{
    if(c=='+' || c=='-')
        return 1;
    if(c=='/' || c=='*')
        return 2;
    if(c=='(')
        return 0;
    return 0;
}

bool isHigher(char c1, char c2)
{
    //cout<<"#"<<c1<<" "<<opVal(c1)<<endl;
    // cout<<"#"<<c2<<" "<<opVal(c2)<<endl;
    return ((opVal(c1) -  opVal(c2)) > 0);
}

int main()
{
    int t;
    bool blank = false;
    char cur;
    scanf("%d",&t);
    getchar();
    getchar();
    while(t--)
    {
        string str;
        stack<char> s;
        if(blank)
            printf("\n");
        blank = true;
        while((cur = getchar()) != '\n' && cur != EOF)
        {
            getchar();
            // cout<<s.size()<<" "<<cur<<" "<<str<<"\n";
            if(isdigit(cur))
            {
                printf("%c",cur);
            }
            else if((cur != ')' && s.empty() || isHigher(cur, s.top())) || cur =='(')
            {
                //cout<<"pus1hed "<<cur<<endl;
                s.push(cur);
            }
            else
            {
                if(cur == ')')
                {
                    while(s.top()!='(' && !s.empty())
                    {
                        printf("%c",s.top());
                        s.pop();
                    }
                    if(!s.empty())
                    {
                        s.pop();
                    }
                }
                else
                {
                    // cout<<"--"<<isHigher(cur, s.top())<<" "<<s.top()<<endl;
                    while(!s.empty() && !isHigher(cur, s.top()))
                    {

                        printf("%c",s.top());
                        s.pop();
                    }
                    s.push(cur);
                    //cout<<"pus2hed "<<cur<<endl;
                }
            }
        }
        while(!s.empty())
        {
            printf("%c",s.top());
            s.pop();
        }
        printf("\n");
    }
    return 0;
}





