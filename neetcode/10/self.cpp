#include <iostream>
#include <string>

class Solution {
public:
	bool isPalindrome(std::string& s)
	{
		int front, back;

		front = next_char(0, s);
		back = prev_char(s.size() - 1, s);

		while (front < s.size()) {
			if (alphanumeric(s[front]) != alphanumeric(s[back]))
				return false;

			front = next_char(front + 1, s);
			back = prev_char(back - 1, s);
		}
		return true;
	}

private:
	char alphanumeric(char c)
	{
		if (0x30 <= c && c <= 0x39)
			return c;

		if (0x41 <= c && c <= 0x5A)
			return c;

		if (0x61 <= c && c <= 0x7A)
			return c - 0x20;

		return -1;
	}

	int next_char(int i, std::string& s)
	{
		while (i != s.size()) {
			if (alphanumeric(s[i]) != -1)
				break;
			i++;
		}
		return i;
	}

	int prev_char(int i, std::string& s)
	{
		while (i != -1) {
			if (alphanumeric(s[i]) != -1)
				break;
			i--;
		}

		return i;
	}

};

int main()
{
	std::string s = "Was it a car or a cat I saw?";

	Solution sol;
	std::cout << sol.isPalindrome(s) << std::endl;
}
