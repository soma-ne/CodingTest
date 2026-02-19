#include <vector>
#include <cmath>

class Solution {
public:
	int findMin(std::vector<int> &nums)
	{
		int n = nums.size();
		int left = nums[0];
		int right = nums[n-1];

		int ng = -1;
		int ok = n;
		while (std::abs(ok - ng) > 1) {
			int mid = (ng + ok) / 2;
			if (nums[mid] <= right) {
				ok = mid;
			} else {
				ng = mid;
			}
		}

		return nums[ok];
	}
};
