#include <iostream>
#include <string>
#include <vector>

#define BOARD_SIZE 9
#define SQUARE_SIZE 3

class Solution {
public:
	bool isValidSudoku(std::vector<std::vector<char>>& board)
	{
		bool ret;
		ret = validify_row(board);
		ret = ret ? validify_column(board) : false;
		ret = ret ? validify_square(board) : false;

		return ret;
	}

private:
	bool validify_row(std::vector<std::vector<char>>& board)
	{
		for (int i=0;i<BOARD_SIZE;i++) {
			std::vector<bool> seen(10, false);
			for (int j=0;j<BOARD_SIZE;j++) {
				if (board[i][j] == '.' || board[i][j] == ',')
					continue;
				if (seen[board[i][j] - '0'] == true)
					return false;
				seen[board[i][j] - '0'] = true;
			}
		}
		return true;
	}

	bool validify_column(std::vector<std::vector<char>>& board)
	{
		for (int i=0;i<BOARD_SIZE;i++) {
			std::vector<bool> seen(10, false);
			for (int j=0;j<BOARD_SIZE;j++) {
				if (board[j][i] == '.' || board[j][i] == ',')
					continue;
				if (seen[board[j][i] - '0'] == true)
					return false;
				seen[board[j][i] - '0'] = true;
			}
		}
		return true;
	}

	bool validify_square(std::vector<std::vector<char>>& board)
	{
		for (int i=0;i<SQUARE_SIZE;i++) {
			for (int j=0;j<SQUARE_SIZE;j++) {
				if (!do_validify_square(board,
						i * SQUARE_SIZE, j * SQUARE_SIZE)) {
					return false;
				}
			}
		}
		return true;
	}

	bool do_validify_square(
			std::vector<std::vector<char>>& board, int x, int y)
	{
		std::vector<bool> seen(10, false);
		for (int i=0;i<SQUARE_SIZE;i++) {
			for (int j=0;j<SQUARE_SIZE;j++) {
				if (board[x+i][y+j] == '.' || board[x+i][y+j] == ',')
					continue;
				if (seen[board[x+i][y+j] - '0'])
					return false;
				seen[board[x+i][y+j] - '0'] = true;
			}
		}
		return true;
	}
};

int main()
{
	std::vector<std::vector<char>> board = {{'1','2','.','.','3','.','.','.','.'},{'4','.','.','5','.','.','.','.','.'},{'.','9','8','.','.','.','.','.','3'},{'5','.','.','.','6','.','.','.','4'},{'.','.','.','8','.','3','.','.','5'},{'7','.','.','.','2','.','.','.','6'},{'.','.','.','.','.','.','2','.','.'},{'.','.','.','4','1','9','.','.','8'},{'.','.','.','.','8','.','.','7','9'}};

	Solution sol;
	bool answer = sol.isValidSudoku(board);
	std::cout << answer << std::endl;
}
