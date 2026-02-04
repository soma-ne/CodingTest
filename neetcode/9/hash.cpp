#include <unordered_set>
#include <unordered_map>
#include <vector>

class Solution {
public:
	int longestConsecutive(std::vector<int>& nums)
	{
		std::unordered_map<int, bool> exist;
		for (auto& i : nums) {
			exist[i] = true;
		}

		std::unordered_map<int, int> len;
		int max = 0;
		for (auto& i : nums) {
			len[i] = search_recursive(len, exist, i);
			max = std::max(max, len[i]);
		}

		return max;
	}

private:
	int search_recursive(
		std::unordered_map<int,int>& len,
		std::unordered_map<int,bool>& exist, int i)
	{
		if (!exist[i+1])
			return 1;

		if (len[i+1] != 0)
			return len[i+1] + 1;

		return search_recursive(len, exist, i+1) + 1;
	}
};
