#include <vector>
#include <algorithm>
#include <cstdlib>

class Solution {
public:
	int search(std::vector<int>& nums, int target) {
		int ng = -1;
		int n = nums.size();
		int ok = n;
		while (std::abs(ok - ng) > 1) {
			int mid = (ng + ok) / 2;
			if (nums[mid] >= target) {
				ok = mid;
			} else {
				ng = mid;
			}
		}

		if (ok == n)
			return -1;
		if (nums[ok] != target)
			return -1;
		return ok;
	}
};
