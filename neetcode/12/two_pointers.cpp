#include <vector>
#include <algorithm>

class Solution {
public:
	std::vector<std::vector<int>> threeSum(std::vector<int>& nums)
	{
		std::vector<std::vector<int>> triplets;
		std::sort(nums.begin(), nums.end());

		for (auto& i:nums) {
			std::cout << i << " ";
		}
		std::cout << std::endl;

		for (int i=nums.size()-1;i>=2;i=prev_number(i,nums)) {
			add_triplets(i, nums, triplets);
		}

		return triplets;
	}

	void add_triplets(int idx, std::vector<int>& nums,
			std::vector<std::vector<int>>& triplets)
	{
		int left = 0, right = idx - 1;
		int target = -1 * nums[idx];
		std::cout << "idx:" << idx << ":" << target << std::endl;
		while (left < right) {
			std::cout << left << ":" << nums[left]
				<< " " << right << ":" <<  nums[right] << " ~~ " << target << std::endl;
			int sum = nums[left] + nums[right];
			if (sum < target) {
				left = next_number(left, nums);
			} else if (sum == target) {
				triplets.push_back({nums[left], nums[right], -1 * target});
				left = next_number(left, nums);
				right = prev_number(right, nums);
			} else if (sum > target) {
				right = prev_number(right, nums);
			}
		}
		std::cout << std::endl;
	}

	int next_number(int idx, std::vector<int>& nums)
	{
		int i;
		for (i=idx;i<nums.size();i++) {
			if (nums[i] != nums[idx])
				break;
		}
		return i;
	}

	int prev_number(int idx, std::vector<int>& nums)
	{
		int i;
		for (i=idx;i>=0;i--) {
			if (nums[i] != nums[idx])
				break;
		}
		return i;
	}
};
