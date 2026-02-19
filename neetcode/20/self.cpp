#include <vector>
#include <queue>
#include <unordered_map>

class Solution
{
public:
	std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k)
	{
		int n = nums.size();
		std::vector<int> ret;
		std::priority_queue<int> order;
		std::unordered_map<int,int> q;


		// initialize
		for (int i=0;i<k;i++) {
			order.push(nums[i]);
		}
		ret.push_back(order.top());

		for (int i=k;i<n;i++) {
			int pop = nums[i-k];
			int push = nums[i];

			// pop
			q[pop]++;

			// push
			order.push(push);

			// check max
			int max;
			while (1) {
				max = order.top();
				// not use [] to avoid creating unnecessary objects
				std::unordered_map<int,int>::iterator it = q.find(max);
				if (it != q.end() && it->second > 0) {
					it->second--;
					order.pop();
				} else {
					break;
			}

			ret.push_back(max);
		}

		return ret;
	}

};

int main()
{
	Solution sol;
	std::vector<int> nums = {1,2,1,0,4,2,6};
	std::vector<int> max = sol.maxSlidingWindow(nums, 3);
}
