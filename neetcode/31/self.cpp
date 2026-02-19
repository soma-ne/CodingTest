#include <vector>

class Solution
{
public:
	int search(std::vector<int>& nums, int target)
	{
		int n = nums.size();
		int left = nums[0];
		int right = nums[n-1];

		int ng = -1;
		int ok = n;
		while (std::abs(ok - ng) > 1) {
			int mid = (ng + ok) / 2;
			if (is_ok(mid, target, nums)) {
				ok = mid;
			} else {
				ng = mid;
			}
		}

		if (ok == n || nums[ok] != target)
			return -1;
		return ok;
	}

private:
	bool is_ok(int mid, int target, std::vector<int>& nums)
	{
		int n = nums.size();
		int left = nums[0];
		int right = nums[n-1];
		int x = nums[mid];
		if (target > right) {
			return (x >= target) || (x <= right);
		} else if (target < left) {
			return (x >= target) && (x < left);
		} else {
			return (x >= target);
		}
	}
};
