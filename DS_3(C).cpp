//Evaluate Prefix Expression

#include<iostream>
#include<stack>
using namespace std;
int main()
{
    string exp;
    stack<int> s;

    cout<<"Enter the prefix expression : "<<endl;
    cin>>exp;

    for(int i=exp.length()-1; i>=0; i++)
    {
        if(exp[i]>='0' && exp[i]<='9')
        {
            s.push(exp[i] - '0');
        }

        else
        {
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();

            if(exp[i] == '+')
            s.push(a+b);
            else if(exp[i] == '-')
            s.push(a-b);
            else if(exp[i] == '*')
            s.push(a*b);
            else if(exp[i] == '/')
            s.push(a/b);
        }
    }
    cout<<"Result = "<<s.top()<<endl;
    return 0;
}