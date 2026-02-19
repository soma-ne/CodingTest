#include <stack>
#include <iostream>
#include <string>

class Solution
{
public:
	bool isValid(std::string s)
	{
		int n = s.size();
		std::stack<char> stack;
		for (int i=0;i<n;i++)
		{
			char c;
			switch (s[i]) {
				case '(':
					stack.push('(');
					break;
				case '{':
					stack.push('{');
					break;
				case '[':
					stack.push('[');
					break;
				case ')':
					if (stack.empty())
						return false;
					c = stack.top();
					stack.pop();
					if (c != '(')
						return false;
					break;
				case '}':
					if (stack.empty())
						return false;
					c = stack.top();
					stack.pop();
					if (c != '{')
						return false;
					break;
				case ']':
					if (stack.empty())
						return false;
					c = stack.top();
					stack.pop();
					if (c != '[')
						return false;
					break;
			}
		}

		if (!stack.empty())
			return false;

		return true;
	}
};

int main()
{
	Solution sol;
	std::string s("[([]}]");
	std::cout << sol.isValid(s) << std::endl;
}
