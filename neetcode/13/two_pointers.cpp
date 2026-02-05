#include <vector>

class Solution {
public:
	int maxArea(std::vector<int>& heights)
	{
		int l = 0, r = heights.size() - 1;
		int max = 0;
		while (l < r) {
			int tmp = std::min(heights[l], heights[r]) * (r - l);
			max = std::max(max, tmp);
			if (heights[l] <= heights[r])
				l++;
			else
				r--;
		}

		return max;
	}
};
