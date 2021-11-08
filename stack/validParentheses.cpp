#include<iostream>
#include<stack>
#include<string>

using namespace std;

bool isOpen(char ch)
{
    return ch == '{' || ch == '[' || ch == '(';
}

bool isPair(char open, char close)
{
    return open == '{' && close == '}' || 
    open == '[' && close == ']'  || 
    open == '(' && close == ')';
}

bool isBalanced(string s)
{
    stack<char> st;

    for(int i = 0; i < s.size(); ++i)
    {
        if(isOpen(s[i]))
        {
            st.push(s[i]);
        }
        else
        {
            if(!st.empty() && isPair(st.top(), s[i]))
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }
    }

    return st.empty();
}

int main()
{
    string s1 = "()({[]}())"; // true
    string s2 = "{}"; // true
    string s3 = "}{"; // false
    string s4 = ""; // true
    string s5 = "(()"; // false
    string s6 = "())"; // false
    string s7 = "[(])"; // false

    cout << isBalanced(s1) << endl;
    cout << isBalanced(s2) << endl;
    cout << isBalanced(s3) << endl;
    cout << isBalanced(s4) << endl;
    cout << isBalanced(s5) << endl;
    cout << isBalanced(s6) << endl;
}
