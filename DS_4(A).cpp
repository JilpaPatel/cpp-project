#include<iostream>
#include<stack>
#include<string>
using namespace std;

int priority(char op)
{
    if(op=='&')
    return 3;
    else if(op=='*' || op=='/')
    return 2;
    else if(op=='+' || op=='-')
    return 1;
    else
    return 0;
}

bool isOperand(char ch)
{
    if((ch>='A' && ch<='Z') ||
       (ch>='a' && ch<='z') ||
       (ch>='0' && ch<='9'))
       return true;
       
    else 
    return false;
}

int main()
{
    string infix, postfix;
    stack<char> st;
    cout<<"Enter the infix expression : "<<endl;
    cin>>infix;
    
    for(int i=0; i<infix.length(); i++)
    {
        char ch = infix[i];
        
        if(ch == ' ')
        continue;
        
        else if(isOperand(ch))
        {
            postfix+=ch;
        }
        
        else if(ch == '(')
        {
            st.push(ch);
        }
        
        else if(ch == ')')
        {
            while(!st.empty() && st.top()!='(')
            {
                postfix+=st.top();
                st.pop();
            }
            
            if(!st.empty())
            {
                st.pop();
            }
        }
        
        else if(ch == '+' || ch=='-' || ch=='*' || ch=='/' || ch=='$')
        {
            while (!st.empty() &&
                   ((priority(st.top()) > priority(ch)) ||
                    (priority(st.top()) == priority(ch) && ch != '$')))
            {
                postfix+=st.top();
                st.pop();
            }
            st.push(ch);
        }
    }
    
    while(!st.empty())
    {
        postfix += st.top();
        st.pop();
    }
    
    cout<<"Postfix expression : "<<postfix<<endl;
    return 0;
}