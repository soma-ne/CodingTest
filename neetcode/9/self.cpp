#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

class Solution {
public:
	int longestConsecutive(std::vector<int>& nums)
	{
		if (nums.size() == 0)
			return 0;

		std::sort(nums.begin(), nums.end());

		int max = 1;
		int cur = 1;
		for (int i=1;i<nums.size();i++) {
			if (nums[i] == nums[i-1] + 1) {
				cur++;
				max = std::max(cur, max);
			} else if (nums[i] > nums[i-1])
				cur = 1;
		}

		return max;
	}
};

int main() {
	Solution sol;
	std::vector<int> nums = {2,20,4,10,3,4,5};
	int answer = sol.longestConsecutive(nums);

	std::cout << answer << std::endl;
}
