/*
In any language program mostly syntax error occurs due to unbalancing delimiter such as
(),{},[]. Write C++ program using stack to check whether given expression is well
parenthesized or not. */

#include <iostream>
using namespace std;

class stack
{
public:
    int size;
    int top;
    char *arr;

    stack(int size)
    {
        this->size = size;
        arr = new char[size];
        top = -1;
    }

    void push(char data)
    {
        if (top==size-1)
        {
            cout << "stack overflow" << endl;
            return;
        }
        top++;
        arr[top] = data;
    }
    char pop()
    {
        if (top == -1)
        {
            cout << "stack underflow" << endl;
            return -1;
        }
        else
        {
            char ele= arr[top];
            top--;
            return ele;
        }
    }

    bool isempty()
    {
        if (top == -1)
            return true;
        else
            return false;
    }

    char gettop()
    {
        if (top == -1)
        {
            cout << "stack underflow" << endl;
            return -1;
        }
        return arr[top];
    }
};

bool matched(char a, char b)
{
    if (a == '{' && b == '}')
    {
        return true;
    }
    else if (a == '(' && b == ')')
    {
        return true;
    }
    else if (a == '[' && b == ']')
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool checkparanthesis(string s)
{
    int n = s.size();
    stack s1(n);
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '[' || s[i] == '{' || s[i] == '(')
        {
            s1.push(s[i]);
        }
        else if (s[i] == ']' || s[i] == '}' || s[i] == ')')
        {
            if (s1.isempty() == false)
            {
                char check = s1.gettop();
                if (matched(check, s[i]))
                {
                    s1.pop();
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
    }
    if (s1.isempty())
        return true;
    else
        return false;
}

int main()
{
    while (true)
    {
        cout << "\n<--------------Menu---------------->" << endl;
        cout << "choose 1.To check the paranthesis :" << endl;
        cout << "choose 2.For Exit!!" << endl;
        cout << "<---------------------------------->" << endl;
        cout << "Enter the choice: ";
        int c;
        cin >> c;
        if (c == 1)
        {
            string s;
            cout << "Enter the Expression : ";
            cin >> s;
            if (checkparanthesis(s))
            {
                cout << "---> Expression is well parenthesized <---" << endl;
            }
            else
            {
                cout << "---> Expression is not properly parenthesized <---" << endl;
            }
            cout << endl;
        }
        else if (c == 2)
        {
            cout << "---> THANKS FOR USING THE PROGRAM <--- " << endl;
            break;
        }
        else
        {
            cout << "---> Enter valid choice <--- " << endl;
        }
    }
    return 0;
}