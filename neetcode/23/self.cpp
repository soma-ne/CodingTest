#include <string>
#include <vector>
#include <iostream>
#include <stack>

class Solution
{
public:
	int evalRPN(std::vector<std::string>& tokens)
	{
		std::stack<int> st;
		int n = tokens.size();

		for (int i=0;i<n;i++) {
			std::string s = tokens[i];
			if (s.size() == 1) {
				if (s[0] == '+') {
					int op2 = st.top();
					st.pop();
					int op1 = st.top();
					st.pop();
					st.push(op1 + op2);
					continue;
				} else if (s[0] == '-') {
					int op2 = st.top();
					st.pop();
					int op1 = st.top();
					st.pop();
					st.push(op1 - op2);
					continue;
				} else if (s[0] == '*') {
					int op2 = st.top();
					st.pop();
					int op1 = st.top();
					st.pop();
					st.push(op1 * op2);
					continue;
				} else if (s[0] == '/') {
					int op2 = st.top();
					st.pop();
					int op1 = st.top();
					st.pop();
					st.push(op1 / op2);
					continue;
				}
			}
			st.push(std::stoi(s));
		}
		return st.top();
	}

};

int main()
{
	Solution sol;
	std::vector<std::string> tokens = {"1","2","+","3","*","4","-"};
	std::cout << sol.evalRPN(tokens) << std::endl;
}
