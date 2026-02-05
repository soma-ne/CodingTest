#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
public:
	std::vector<std::vector<int>> threeSum(std::vector<int>& nums)
	{
		std::vector<std::vector<int>> triplets;
		std::vector<std::vector<int>> answer;
		std::sort(nums.begin(), nums.end());
		bool zero = false;
		for (int i=2;i<nums.size();i++) {
			add_triplets(i, nums, triplets, zero);
		}
		for (auto t: triplets) {
			for (auto n: t) {
				std::cout << n << " ";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
		std::stable_sort(triplets.begin(), triplets.end(),
			[](auto& a, auto& b){
				return a[0] < b[0];
		});
		std::stable_sort(triplets.begin(), triplets.end(),
			[](auto& a, auto& b){
				return a[1] < b[1];
		});
		std::stable_sort(triplets.begin(), triplets.end(),
			[](auto& a, auto& b){
				return a[2] < b[2];
		});
		for (auto t: triplets) {
			for (auto n: t) {
				std::cout << n << " ";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
		if (triplets.empty())
			return {};
		std::vector<int> cur = triplets[0];
		answer.push_back(triplets[0]);
		for (int i=0;i<triplets.size();i++) {
			if (triplets[i][0] == cur[0] &&
				triplets[i][1] == cur[1] &&
				triplets[i][2] == cur[2])
				continue;
			cur = triplets[i];
			answer.push_back(triplets[i]);
		}
		return answer;
	}

	void test()
	{
		//std::vector<int> nums = {-1,0,1,2,-1,-4};
		std::vector<int> nums = {0,1,1};
		std::vector<std::vector<int>> answer =
			threeSum(nums);

		for (auto t: answer) {
			for (auto n: t) {
				std::cout << n << " ";
			}
			std::cout << std::endl;
		}
	}
private:
	void add_triplets(int idx,
			std::vector<int>& nums,
			std::vector<std::vector<int>>& triplets,
			bool& zero)
	{
		int target = -1 * nums[idx];
		int left = 0, right = idx - 1;
		while (left < right) {
			if (nums[left] + nums[right] < target) {
				left++;
			} else if(nums[left] + nums[right] == target) {
				std::cout << left << ":" << right << ":" << idx << std::endl;
				triplets.push_back({nums[left], nums[right], -1 * target});
				left = next_num(left, nums);
				right = prev_num(right, nums);
			} else if (nums[left] + nums[right] > target) {
				right--;
			}
		}
		return;
	}

	int next_num(int idx, std::vector<int>& nums)
	{
		int i;
		for (i=idx;i<nums.size();i++) {
			if (nums[i] != nums[idx])
				break;
		}
		return i;
	}

	int prev_num(int idx, std::vector<int>& nums)
	{
		int i;
		for (i=idx;i>=0;i--) {
			if (nums[i] != nums[idx])
				break;
		}
		return i;
	}
};

int main()
{
	Solution sol;
	sol.test();
}
