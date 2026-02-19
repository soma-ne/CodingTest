#include <stack>
#include <vector>

class Solution
{
public:
	std::vector<int> dailyTemperatures(std::vector<int>& temp)
	{
		std::stack<std::pair<int,int>> st;
		int n = temp.size();
		std::vector<int> result(n);

		for (int i=0;i<n;i++) {
			while(1) {
				if (st.empty()) {
					st.emplace(temp[i], i);
					break;
				}

				std::pair<int,int> top = st.top();

				if (top.first < temp[i]) {
					st.pop();
					result[top.second] = i - top.second;
				} else {
					st.emplace(temp[i], i);
					break;
				}
			}
		}

		return result;
	}
};
