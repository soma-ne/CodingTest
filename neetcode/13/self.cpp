#include <vector>

class Solution {
public:
	int maxArea(std::vector<int>& heights)
	{
		std::vector<std::pair<int,int>> large;
		for (int i=0;i<heights.size();i++) {
			large.push_back({heights[i],i});
		}
		std::sort(large.rbegin(), large.rend());

		int first = 0, second = 1;
		int amount = large[1].first * distance(0, 1, large);
		for (int i=2;i<large.size();i++) {
			int first_water = large[i].first * distance(i, first, large);
			int second_water = large[i].first * distance(i, second, large);
			if (first_water > amount) {
				amount = first_water;
				second = i;
			} if (second_water > amount) {
				amount = second_water;
				first = i;
			}
		}
		return amount;
	}

private:
	int distance(int i, int j, std::vector<std::pair<int,int>>& heights)
	{
		int i_idx = heights[i].second;
		int j_idx = heights[j].second;
		return (i_idx > j_idx) ? (i_idx - j_idx) : (j_idx - i_idx);
	}
};
