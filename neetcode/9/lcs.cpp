#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
	int longestConsecutive(std::vector<int>& nums)
	{
		int max = 0;
		std::unordered_map<int,int> table;
		for (int i=1;i<nums.size();i++) {
			table[nums[i]] = table[nums[i]-1] + 1;
			max = std::max(table[nums[i]], max);
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
