#include <vector>
#include <iostream>

class Solution {
public:
    int findDuplicate(std::vector<int>& nums)
	{
		int fast = 0, slow = 0;

		fast = nums[fast];
		fast = nums[fast];
		slow = nums[slow];
		while (fast != slow) {
			fast = nums[fast];
			fast = nums[fast];
			slow = nums[slow];
		}

		int ptr = 0;
		while (ptr != slow) {
			ptr = nums[ptr];
			slow = nums[slow];
		}

		return ptr;
    }
};


int main()
{
	std::vector<int> nums = {1,2,3,2,2};
	Solution sol;
	std::cout << sol.findDuplicate(nums) << std::endl;
}
