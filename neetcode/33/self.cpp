#include <vector>
#include <cmath>

class Solution
{
public:
	double findMedianSortedArrays(
			std::vector<int>& nums1, std::vector<int>& nums2)
	{
		int n = nums1.size();
		int m = nums2.size();
		int sum = n + m;

		int ng = -1;
		int ok = n;
		while (std::abs(ok - ng) > 1) {
			int mid = (ok + ng) / 2;
			if (is_ok(mid, nums1, nums2)) {
				ok = mid;
			} else {
				ng = mid;
			}
		}

		int idx1 = ok;
		int idx2 = std::lower_bound(
				nums2.begin(), nums2.end(), nums1[idx]) - nums2.begin();
		if (sum % 2 == 0) {
			std::vector<int> order ;
		} else {
		}
	}

private:
	bool is_ok(int idx1, std::vector<int>& nums1, std::vector<int>& nums2)
	{
		int n = nums1.size();
		int m = nums2.size();
		int sum = n + m;

		auto it2 = std::lower_bound(nums2.begin(),
				nums2.end(), nums1[idx1]);
		int idx2 = it2 - nums2.begin();

		int right = (n - idx1) + (m - idx2);
		int left = n + m - right;

		if (sum % 2 == 0) {
			return left >= right;
		} else {
			return left > right;
		}
	}
};
