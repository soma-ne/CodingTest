#include <string>
#include <queue>
#include <iostream>

class Solution
{
public:
	int characterReplacement(std::string s, int k)
	{
		int n = s.size();

		int max = 0;
		for (int i=0;i<=idx('Z');i++) {
			int len = 0, max_len = 0;
			int remain = k;
			std::queue<int> others;

			for (int j=0;j<n;j++) {
				if (s[j] == 'A' + i) {
					len++;
				} else if (k == 0) {
					len = 0;
				} else if (remain > 0) {
					remain--;
					len++;
					others.push(j);
				} else {
					int top = others.front();
					others.pop();
					len = j - top;
					others.push(j);
				}

				max_len = std::max(max_len, len);
			}

			max = std::max(max, max_len);
		}

		return max;
	}

	int idx(char c)
	{
		return (int)(c - 'A');
	}
};

int main()
{
	Solution sol;
	int ans = sol.characterReplacement("AAABABBABAA", 1);
	std::cout << ans << std::endl;
}
