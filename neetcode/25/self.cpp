#include <vector>
#include <stack>
#include <algorithm>

class Solution
{
public:
	int carFleet(int target, std::vector<int>& position,
				std::vector<int>& speed)
	{
		int n = position.size();
		std::vector<std::pair<int,int>> car(n);
		for (int i=0;i<n;i++) {
			car[i] = {position[i], speed[i]};
		}
		std::sort(car.begin(), car.end());

		std::stack<std::pair<int,int>> st;
		for (int i=n-1;i>=0;i--) {
			while (1) {
				if (st.empty()) {
					st.push(car[i]);
					break;
				}
				std::pair<int,int> top = st.top();
				if (fast(car[i], top, target)) {
					break;
				} else {
					st.push(car[i]);
					break;
				}
			}
		}

		return st.size();
	}

private:
	bool fast(std::pair<int,int> c1, std::pair<int,int> c2, int target)
	{
		int l1 = c1.first;
		int l2 = c2.first;
		int s1 = c1.second;
		int s2 = c2.second;

		return (target - l1) * s2 <= (target - l2) * s1;
	}
};

