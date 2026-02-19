#include <vector>
#include <iostream>
#include <algorithm>

class Solution {
public:
	int trap(std::vector<int>& height)
	{
		std::vector<std::pair<int,int>> bars;
		for (int i=0;i<height.size();i++) {
			bars.push_back({height[i], i});
		}

		std::sort(bars.rbegin(), bars.rend());

		std::vector<bool> filled(height.size());

		int l, r;
		int l_h, r_h;
		int water = 0;
		if (bars[0].second < bars[1].second) {
			l = bars[0].second;
			r = bars[1].second;
		} else {
			l = bars[1].second;
			r = bars[0].second;
		}

		water += pour(l, r, height, filled);

		for (int i=2;i<bars.size();i++) {
			if (filled[bars[i].second])
				continue;

			int idx = bars[i].second;

			if (idx > r) {
				water += pour(r, idx, height, filled);
				r = idx;
			} else if (idx < l){
				water += pour(idx, l, height, filled);
				l = idx;
			} else {
				std::cout << "ERROR" << std::endl;
				return -1;
			}
		}

		return water;
	}

	int pour(int left, int right,
			std::vector<int>& height,
			std::vector<bool>& filled)
	{
		int water = 0;
		int level = std::min(height[left], height[right]);

		for (int i=left+1;i<right;i++) {
			filled[i] = true;
			water += level - height[i];
		}

		return water;
	}

	void test()
	{
		std::vector<int> test_case = {0,2,0,3,1,0,1,3,2,1};
		int ans = trap(test_case);
		std::cout << "==ANS======" << std::endl;
		std::cout << ans << std::endl;
		std::cout << "===========" << std::endl;
	}
};

int main()
{
	Solution sol;
	sol.test();
}
