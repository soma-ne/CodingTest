#include <vector>
#include <stack>
#include <iostream>

class Solution
{
public:
	int largestRectangleArea(std::vector<int>& h)
	{
		int n = h.size();
		std::stack<std::pair<int,int>> st;
		int max = -1;

		for (int i=0;i<n;i++) {
			std::cout << "i:" << i << " h:" << h[i] << std::endl;
			int cnt = 1;
			while (1) {
				std::pair<int,int> top;
				if (!st.empty())
					top = st.top();
				if (st.empty() || top.first < h[i]) {
					st.emplace(h[i], cnt);
					break;
				} else {
					cnt += top.second;
					st.pop();
					max = std::max(max, top.first * (cnt - 1));
				}
			}
			std::cout << "max:" << max << std::endl;
			std::cout << std::endl;
		}

		int cnt = 0;
		while (!st.empty()) {
			auto top = st.top();
			st.pop();
			cnt += top.second;
			max = std::max(max, top.first * cnt);
		}

		return max;
	}
};

int main()
{
	Solution sol;
	std::vector<int> h = {2,1,5,6,2,3};
	std::cout << sol.largestRectangleArea(h) << std::endl;
}
