#include <unordered_map>
#include <string>

class Solution {
public:
	int lengthOfLongestSubstring(std::string s) {
		int n = s.length();
		if (n == 0)
			return 0;
		std::unordered_map<char,int> table;
		int max = 1;
		int cur = 0;
		for (int i=0;i<n;i++) {
			if (table.contains(s[i])) {
				int seen = table[s[i]];
				cur = std::min(i - seen, cur + 1);
			} else
				cur++;

			max = std::max(max, cur);
			table[s[i]] = i;
		}
		return max;
	}
};

