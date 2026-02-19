#include <string>
#include <queue>
#include <vector>
#include <iostream>

class Solution
{
public:
	bool checkInclusion(std::string s1, std::string s2)
	{
		if (s1.size() > s2.size())
			return false;

		std::vector<int> initial(26);
		std::vector<bool> exist(26);
		for (int i=0;i<s1.size();i++) {
			initial[idx(s1[i])]++;
			exist[idx(s1[i])] = true;
		}


		int size = s1.size();
		int len = 0;
		std::vector<int> count = initial;
		for (int i=0;i<s2.size();i++) {
			char cur = idx(s2[i]);
			int cnt = count[cur];
			if (count[cur] > 0) {
				count[idx(s2[i])]--;
				len++;
				if (len == size)
					return true;
			} else if (count[cur] == 0) {
				if (exist[cur]) {
					int tmp = len;
					for (int j=0;j<len;j++) {
						if (s2[i-len+j] == s2[i])
							break;
						if (exist[idx(s2[i-len+j])])
							count[idx(s2[i-len+j])]++;
						tmp--;
					}
					len = tmp;
				} else {
					count = initial;
					len = 0;
				}
			}
			std::cout << "char: " << s2[i] << " len:" << len
				<< " count[" << s2[i] << len << "]:" << cnt
				<< " -> " << count[idx(s2[i])]
				<< std::endl;
		}

		return false;
	}

	int idx(char s) {
		return (int)(s - 'a');
	}
};

int main()
{
	Solution sol;
	std::cout << sol.checkInclusion("ky", "ainwkckifykxlribaypk") << std::endl;
}
