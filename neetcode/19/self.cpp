#include <string>
#include <unordered_map>
#include <iostream>

class Solution
{
public:
	std::string minWindow(std::string s, std::string t)
	{
		int n = s.size();
		if (n < t.size())
			return "";

		std::unordered_map<char, int> mp;
		for (auto& c: t) {
			mp[c]++;
		}

		std::string ret = "";
		std::unordered_map<char, int> cnt;
		int l = n;
		int num = t.size();
		int min = n+1;
		for (int i=0;i<n;i++) {

			if (mp[s[i]] == 0)
				continue;

			if (mp[s[i]] > 0) {
				cnt[s[i]]++;

				if (l == n) {
					l = i;
					num--;
				} else if (cnt[s[i]] > mp[s[i]]) {
					// shrink
					for (;l<=i;l++) {
						std::cout << s[l];
						if (mp[s[l]] == 0) {
							continue;
						} else if (cnt[s[l]] > mp[s[l]]) {
							cnt[s[l]]--;
							continue;
						} else {
							break;
						}
					}
					std::cout << std::endl;
				} else {
					num--;
				}
			}

			if (num == 0 && i - l + 1 < min) {
				ret = s.substr(l, i - l + 1);
				min = i - l + 1;
			}
			std::cout << s.substr(0, i+1) << std::endl;
			std::cout << "l:" << l << " min:" << min << " num:" << num <<  std::endl;
			std::cout << "A:" << cnt['A'] << " B:" << cnt['B'] << " C:" << cnt['C'] << std::endl;
			std::cout << std::endl;
		}

		return ret;
	}
};

int main()
{
	Solution sol;
	std::cout << sol.minWindow("a", "a") << std::endl;
}
