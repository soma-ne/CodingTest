#include <stack>

class MinStack {
public:
    MinStack() {
    }

    void push(int val) {
		st.push(val);
		int min = val;
		if (!min_st.empty())
			min = min_st.top();
		min_st.push(std::min(min, val));
    }

    void pop() {
		st.pop();
		min_st.pop();
    }

    int top() {
		return st.top();
    }

    int getMin() {
		return min_st.top();
    }
private:
	std::stack<int> st;
	std::stack<int> min_st;
};

