#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>

class Solution
{
public:
	int minEatingSpeed(std::vector<int>& piles, int h)
	{
		int min = 1e9 + 1, max = 0;
		for (auto x : piles) {
			max = std::max(max, x);
			min = std::min(min, x);
		}

		int ng = 0;
		int ok = max + 1;

		while (std::abs(ng - ok) > 1) {
			int mid = (ng + ok) / 2;
			if (is_ok(mid, h, piles)) {
				ok = mid;
			} else {
				ng = mid;
			}
		}
		return ok;
	}
private:
	bool is_ok(int k, int h, std::vector<int>& piles)
	{
		int time = 0;
		for (auto x: piles) {
			time += x / k;
			if (x % k != 0)
				time++;
		}
		return time <= h;
	}
};

int main()
{
	std::vector<int> piles = {31284470};
	int h = 31284469;
	Solution sol;
	std::cout << sol.minEatingSpeed(piles, h) << std::endl;
}
