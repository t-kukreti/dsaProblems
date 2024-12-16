#include <iostream>
#include <stack>
using namespace std;
bool validparenthesis(string s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        // opening bracket
        if (ch == '(' || ch == '{' || ch == '[')
        {
            st.push(ch);
        }
        // closing bracket
        else
        {
            if (!st.empty())
            {
                if ((ch == ')' && st.top() == '(') || (ch == '}' && st.top() == '{') || (ch == ']' && st.top() == '['))
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
        if (st.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}
int main()
{
    string s = "[{()}]";
    cout<<validparenthesis(s)<<endl;
    return 0;
}