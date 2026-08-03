#include <iostream>
#include <stack>
#include <string>
using namespace std;

int priority(char op)
{
    if(op == '^')
        return 3;
    else if(op == '*' || op == '/')
        return 2;
    else if(op == '+' || op == '-')
        return 1;
    else
        return 0;
}

bool isOperand(char ch)
{
    return (isalnum(ch));
}

int main()
{
    string infix, postfix;
    stack<char> st;

    cout << "Enter the infix expression: ";
    getline(cin, infix);

    for(int i = 0; i < infix.length(); i++)
    {
        char ch = infix[i];

        if(ch == ' ')
            continue;

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

            if(!st.empty())
                st.pop();
        }

        else
        {
            while(!st.empty() && st.top() != '(' &&
                 (priority(st.top()) > priority(ch) ||
                 (priority(st.top()) == priority(ch) && ch != '^')))
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

    cout << "Postfix expression: " << postfix << endl;

    return 0;
}