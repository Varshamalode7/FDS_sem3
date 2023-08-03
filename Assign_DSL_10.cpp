/*Implement C++ program for expression conversion as infix to postfix and its evaluation
using stack based on given conditions: 1. Operands and operator, both must be single
character. 2. Input Postfix expression must be in a desired format. 3. Only '+', '-', '*' and '/ '
operators are expected.*/

#include <iostream>
using namespace std;
template <class T>
class stack
{
public:
	int size, top;
	T *arr;

	stack(int size)
	{
		this->size = size;
		arr = new T[size];
		top = -1;
	}

	void push(T data)
	{
		if (top == size - 1)
		{
			cout << "stack overflow" << endl;
			return;
		}
		top++;
		arr[top] = data;
	}

	T pop()
	{
		if (top == -1)
		{
			cout << "stack underflow" << endl;
			return '-';
		}
		else
		{
			T ele = arr[top];
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

	T gettop()
	{
		if (top == -1)
		{
			cout << "stack underflow" << endl;
			return -1;
		}
		return arr[top];
	}
};

bool isOperand(char a)
{
	if (a == '+' || a == '-' || a == '/' || a == '*' || a == '(' || a == ')')
	{
		return false;
	}
	else
		return true;
}

int pre(char a)
{
	if (a == '+' || a == '-')
	{
		return 1;
	}
	else if (a == '/' || a == '*')
	{
		return 2;
	}
}

string convert(string s)
{
	string ans = "";
	stack<char> st(52);

	for (int i = 0; i < s.size(); i++)
	{
		if (isOperand(s[i]))
		{
			ans = ans + s[i];
		}
		else if (s[i] == '(')
		{
			st.push(s[i]);
		}
		else if (s[i] == ')')
		{
			while (st.gettop() != '(')
			{
				ans = ans + st.gettop();
				st.pop();
			}
			st.pop();
		}
		else if (isOperand(s[i]) == false)
		{
			while ((!st.isempty()) && (st.gettop() != '(') && (pre(s[i]) <= pre(st.gettop())))
			{
				ans = ans + st.gettop();
				st.pop();
			}
			st.push(s[i]);
		}
	}
	while (!st.isempty())
	{
		ans = ans + st.pop();
	}
	cout << ans << endl;
	return ans;
}

int evaluation(string s)
{
	stack<int> st(100);
	for (int i = 0; i < s.size(); i++)
	{
		if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
		{
			cout << "Enter the value of " << s[i] << endl;
			int t;
			cin >> t;
			st.push(t);
		}
		else
		{
			int x1, x2, r;
			x2 = st.pop();
			x1 = st.pop();

			switch (s[i])
			{
			case '+':
				r = x1 + x2;
				st.push(r);
				break;
			case '-':
				r = x1 - x2;
				st.push(r);
				break;
			case '*':
				r = x1 * x2;
				st.push(r);
				break;
			case '/':
				r = x1 / x2;
				st.push(r);
				break;

			default:
				break;
			}
		}
	}
	cout << endl;
	cout << "Answer of the given epression : ";
	cout << st.pop() << endl;
}

int main()
{
	string s;
	cout << "Enter the string : ";
	cin >> s;
	while (true)
	{
		cout << "\n<--------------Menu---------------->" << endl;
		cout << "choose 1. for INFIX to POSTFIX :" << endl;
		cout << "choose 2. for EVALUATION :" << endl;
		cout << "choose 3. For Exit!!" << endl;
		cout << "<---------------------------------->" << endl;
		cout << "Enter the choice: ";
		int c;
		cin >> c;
		if (c == 1)
		{

			convert(s);
		}
		else if (c == 2)
		{
			evaluation(convert(s));
		}
		else if (c == 3)
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