#include <iostream>
#include <vector>

class Solution
{
public:
	int maxProfit(std::vector<int>& prices)
	{
		int n = prices.size();
		int max = prices[n-1];
		int max_profit = 0;

		for (int i=n-2;i>=0;i--) {
			max = std::max(max, prices[i+1]);
			max_profit = std::max(max_profit, max - prices[i]);
		}

		return max_profit;
	}
};
