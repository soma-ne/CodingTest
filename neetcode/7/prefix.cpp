#include <iostream>
#include <vector>

class Solution {
	std::vector<int> productExceptSelf(std::vector<int>& nums)
	{
		std::vector<int> prefix = {1};
		std::vector<int> suffix = {1};
		std::vector<int> result(nums.size());

		for (int i=1;i<nums.size();i++) {
			prefix.push_back(prefix[i-1] * nums[i-1]);
		}

		for (int i=1;i<nums.size();i++) {
			suffix.push_back(suffix[i-1] * nums[nums.size()-i]);
		}

		for (int i=0;i<nums.size();i++) {
			result[i] = prefix[i] * suffix[nums.size()-1-i];
		}

		return result;
	}
};
