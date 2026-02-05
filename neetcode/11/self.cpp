#include <vector>
#include <iostream>

class Solution {
	public:
		std::vector<int> twoSum(std::vector<int>& numbers, int target)
		{
			int left = 0, right = numbers.size() - 1;
			while (left != right) {
				if (numbers[left] + numbers[right] < target) {
					left++;
				} else if (numbers[left] + numbers[right] ==  target) {
					break;
				} else if (numbers[left] + numbers[right] > target) {
					right--;
				}
			}

			return {left + 1, right + 1};
		}

		void test()
		{
			std::vector<int> numbers = {1,2,3,5,7,12,13,13,15};
			int target = 12;

			std::vector<int> answer = twoSum(numbers, target);
			std::cout << answer[0] << ":" << answer[1] << std::endl;
		}
};

int main()
{
	Solution sol;
	sol.test();
}
