#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>

class Solution {
public:
	std::vector<std::vector<std::string>>
		groupAnagrams(std::vector<std::string>& strs)
	{
		std::vector<std::vector<std::string>> groups_sz
			= sort_by_size(strs);

		std::cout << "==================" << std::endl;
		for (int i=0;i<groups_sz.size();i++) {
			for (int j=0;j<groups_sz[i].size();j++) {
				std::cout << groups_sz[i][j] << " ";
			}
			std::cout << std::endl;
		}
		std::cout << "==================" << std::endl;


		std::vector<std::vector<std::string>> anagrams;
		for (int i=0;i<groups_sz.size();i++) {
			do_group_anagrams(groups_sz[i], anagrams);
		}

		return anagrams;
	}

private:
	std::vector<std::vector<std::string>>
		sort_by_size(std::vector<std::string>& strs)
	{
		std::sort(strs.begin(), strs.end(),
			[](auto& a, auto& b){return a.size() < b.size();});
		std::vector<std::vector<std::string>> groups;
		std::vector<std::string> cur;
		int tmp_sz = -1;
		for (int i=0;i<strs.size();i++) {
			if ((int)strs[i].size() > tmp_sz) {
				cur = {strs[i]};
				groups.push_back(cur);
				tmp_sz = strs[i].size();
			} else {
				std::vector<std::string>& back = groups.back();
				back.push_back(strs[i]);
			}
		}
		return groups;
	}

	void do_group_anagrams(
		std::vector<std::string>& group,
		std::vector<std::vector<std::string>>& result)
	{
		std::vector<std::pair<std::string, std::string>> pairs;
		for (int i=0;i<group.size();i++) {
			pairs.push_back({group[i], group[i]});
		}

		for (int i=0;i<pairs.size();i++) {
			std::sort(pairs[i].first.begin(), pairs[i].first.end());
		}

		std::sort(pairs.begin(), pairs.end());
		std::cout << "==================" << std::endl;
		for (int i=0;i<pairs.size();i++) {
			std::cout << pairs[i].first << ":" << pairs[i].second
				<< "  ";
		}
		std::cout << std::endl << "==================" << std::endl;

		std::string cur_str = pairs[0].first;
		std::vector<std::string> cur_group = {pairs[0].second};
		result.push_back(cur_group);

		for (int i=1;i<pairs.size();i++) {
			if (pairs[i].first == cur_str) {
				std::vector<std::string>& back = result.back();
				back.push_back(pairs[i].second);
			} else {
				cur_str = pairs[i].first;
				cur_group = {pairs[i].second};
				result.push_back(cur_group);
			}
		}
	}
};

int main()
{
	Solution sol;

	std::vector<std::string> strs =
//		{"", "a", "b", "a", "abc", "aac", "caa"};
		{"act","pots","tops","cat","stop","hat"};

	std::vector<std::vector<std::string>> answer =
		sol.groupAnagrams(strs);

	std::cout << answer.size() << std::endl;

	for (int i=0;i<answer.size();i++) {
		for (int j=0;j<answer[i].size();j++) {
			std::cout << answer[i][j] << " ";
		}
		std::cout << std::endl;
	}

	return 0;
}
