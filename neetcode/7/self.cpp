#include <vector>
#include <iostream>

class Solution {
public:
	std::vector<int> productExceptSelf(std::vector<int>& nums)
	{
		int product = 1;
		int zero = 0;
		for (auto& num: nums) {
			if (num == 0) {
				zero++;
			} else {
				product *= num;
			}
		}

		std::vector<int> result;
		for (auto& num: nums) {
			if (num == 0) {
				if (zero >= 2) {
					result.push_back(0);
				} else {
					result.push_back(product);
				}
			} else if (zero != 0) {
				result.push_back(0);
			} else {
				result.push_back(product / num);
			}
		}

		return result;
	}
};

int main()
{
	Solution sol;
	//std::vector<int> nums = {2, 4, 20, -10, 3, 8};
	std::vector<int> nums = {-1,0,1,2,3};
	std::vector<int> result = sol.productExceptSelf(nums);
	for (auto& val: result) {
		std::cout << val << ", ";
	}
	std::cout << std::endl;
}
