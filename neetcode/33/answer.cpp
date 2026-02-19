#include <vector>
#include <algorithm>
#include <iostream>

class Solution
{
public:
	double findMedianSortedArrays(
			std::vector<int>& nums1,
			std::vector<int>& nums2)
	{
		int n = nums1.size();
		int m = nums2.size();
		int sum = n + m;
		if (sum % 2 == 0) {
			int mid1 = get_kth(sum / 2, nums1, nums2);
			int mid2 = get_kth(sum / 2 + 1, nums1, nums2);
			return ((double)mid1 + (double)mid2) / 2;
		} else {
			int mid = get_kth(sum / 2 + 1, nums1, nums2);
			return (double)mid;
		}
	}


	int get_kth(int k, std::vector<int>& nums1, std::vector<int>& nums2)
	{
		std::vector<int>& s = (nums1.size() <= nums2.size()) ?
								nums1 : nums2;
		std::vector<int>& l = (nums1.size() <= nums2.size()) ?
								nums2 : nums1;

		int n = s.size();
		int m = l.size();

		int sl = 0, ll = 0;

		while (1) {
			if (sl == n) {
				return l[k-1];
			}

			if (k == 1) {
				return std::min(s[sl], l[ll]);
			}

			int half = k / 2;
			int s_half = std::min(n - sl, half);
			int l_half = half;
			if (s[sl + s_half - 1] < l[ll + l_half - 1]) {
				sl += s_half;
				k -= s_half;
			} else {
				ll += l_half;
				k -= l_half;
			}
		}
	}
};

int main()
{
	Solution sol;
	std::vector<int> nums1 = {1,2};
	std::vector<int> nums2 = {3,4};
	std::cout << sol.findMedianSortedArrays(nums1, nums2) << std::endl;
}
