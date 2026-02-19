#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
public:
	bool searchMatrix(std::vector<std::vector<int>>& matrix, int target)
	{
		int m = matrix.size();
		int n = matrix[0].size();

		std::vector<int> vec(m);
		for (int i=0;i<m;i++) {
			vec[i] = matrix[i][0];
		}

		auto it = std::upper_bound(vec.begin(), vec.end(), target);
		if (it == vec.begin())
			return false;

		int row = it - vec.begin() - 1;
		it = std::lower_bound(matrix[row].begin(), matrix[row].end(),
								target);
		int column = it - matrix[row].begin();

		if (matrix[row][column] != target)
			return false;

		return true;
	}
};

int main()
{
	Solution sol;
	int target = 13;
	std::vector<std::vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
	sol.searchMatrix(matrix, target);
}
