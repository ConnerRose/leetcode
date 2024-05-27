#include <vector>

class Solution {
 public:
  static auto isValidSudoku(std::vector<std::vector<char>>& board) -> bool {
    using board_t = std::vector<std::vector<bool>>;
    board_t rows(9, std::vector<bool>(9, false));
    board_t cols(9, std::vector<bool>(9, false));
    board_t squares(9, std::vector<bool>(9, false));

    for (size_t i = 0; i < board.size(); ++i) {
      for (size_t j = 0; j < board[i].size(); ++j) {
        if (board[i][j] == '.') {
          continue;
        }
        int num = board[i][j] - '0' - 1;
        size_t square = i / 3 * 3 + j / 3;
        if (rows[i][num] || cols[j][num] || squares[square][num]) {
          return false;
        }
        rows[i][num] = cols[j][num] = squares[square][num] = true;
      }
    }

    return true;
  }
};
