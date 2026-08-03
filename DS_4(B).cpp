#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int priority(char ch)
{
    if(ch == '^')
        return 3;
    else if(ch == '*' || ch == '/')
        return 2;
    else if(ch == '+' || ch == '-')
        return 1;
    else
        return 0;
}

bool isOperand(char ch)
{
    return ((ch >= 'A' && ch <= 'Z') ||
            (ch >= 'a' && ch <= 'z') ||
            (ch >= '0' && ch <= '9'));
}

int main()
{
    string infix, postfix = "", prefix = "";
    stack<char> st;

    cout << "Enter Infix Expression: ";
    cin >> infix;

    reverse(infix.begin(), infix.end());

    for(int i = 0; i < infix.length(); i++)
    {
        if(infix[i] == '(')
            infix[i] = ')';
        else if(infix[i] == ')')
            infix[i] = '(';
    }

    for(int i = 0; i < infix.length(); i++)
    {
        char ch = infix[i];

        if(isOperand(ch))
        {
            postfix += ch;
        }
        else if(ch == '(')
        {
            st.push(ch);
        }
        else if(ch == ')')
        {
            while(!st.empty() && st.top() != '(')
            {
                postfix += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while(!st.empty() && priority(st.top()) >= priority(ch))
            {
                postfix += st.top();
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

    reverse(postfix.begin(), postfix.end());

    cout << "Prefix Expression: " << postfix;

    return 0;
}