#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>
#include <string>

class Solution {
public:
	std::vector<std::vector<std::string>>
		groupAnagrams(std::vector<std::string>& strs)
	{
		std::unordered_map<std::string, std::vector<std::string>> res;
		for (auto& s : strs) {
			std::string sorted = s;
			std::sort(sorted.begin(), sorted.end());
			res[sorted].push_back(s);
		}
		std::vector<std::vector<std::string>> result;
		for (auto& pair : res) {
			result.push_back(pair.second);
		}
		return result;
	}
};

int main()
{
	std::vector<std::string> strs =
		{"", "a", "abc", "aac", "caa", "abcd"};

	Solution sol;
	std::vector<std::vector<std::string>> result
		= sol.groupAnagrams(strs);

	for (int i=0;i<result.size();i++) {
		for (int j=0;j<result[i].size();j++) {
			std::cout << result[i][j] << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}
