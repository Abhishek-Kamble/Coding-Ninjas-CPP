//check redundant breckets
#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool checkRedundantBrackets(string expression)
{
    stack<char> s;
    for (int i = 0; i < expression.length(); i++)
    {
        char frontCh = s.top();
        s.pop();

        bool flg = true;

        if (expression[i] != ')')
        {
            s.push(expression[i]);
        }
        else if (expression[i] == ')')
        {
            frontCh = s.top();
            while (!s.empty() && frontCh != '(')
            {
                if (frontCh == '+' || frontCh == '/' || frontCh == '-' || frontCh == '*')
                {
                    flg = false;
                }
                frontCh = s.top();
                s.pop();

                if (flg)
                    return true;
            }
        }
    }

    return false;
}

int main()
{
    string input;
    cin >> input;
    cout << ((checkRedundantBrackets(input)) ? "true" : "false");
}