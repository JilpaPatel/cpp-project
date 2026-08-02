#include<iostream>
#include<stack>
using namespace std;
int main()
{
    string exp;
    stack<int> s;

    cout<<"Enter the postfix expression : "<<endl;
    cin>>exp;

    for(int i=0; i<exp.length(); i++)
    {
        if(exp[i]>='0' && exp[i]<='9')
        {
            s.push(exp[i] - '0');
        }

        else
        {
            int b = s.top();
            s.pop();
            int a = s.top();
            s.pop();

            if(exp[i] == '+')
            s.push(b+a);
            else if(exp[i] == '-')
            s.push(b-a);
            else if(exp[i] == '*')
            s.push(b*a);
            else if(exp[i] == '/')
            s.push(b/a);
        }
    }
    cout<<"Result = "<<s.top()<<endl;
    return 0;
}