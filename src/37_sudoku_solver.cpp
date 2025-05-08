#include <array>
#include <vector>

class Solution {
 private:
  std::array<std::array<bool, 9>, 9> row = {{{false}}};
  std::array<std::array<bool, 9>, 9> col = {{{false}}};
  std::array<std::array<bool, 9>, 9> square = {{{false}}};

 public:
  auto solveSudoku(std::vector<std::vector<char>>& board) -> void {
    for (int r = 0; r < 9; r++) {
      for (int c = 0; c < 9; c++) {
        if (board[r][c] != '.') {
          int d = board[r][c] - '1';
          row[r][d] = true;
          col[c][d] = true;
          square[3 * (r / 3) + c / 3][d] = true;
        }
      }
    }

    solveSudoku(board, 0, 0);
  }

 private:
  constexpr auto check(int r, int c, int val) -> bool {
    return !(row[r][val] || col[c][val] || square[3 * (r / 3) + c / 3][val]);
  }

  auto solveSudoku(std::vector<std::vector<char>>& board, int r,
                   int c) -> bool {
    if (r == 9) {
      return true;
    }
    if (c == 9) {
      return solveSudoku(board, r + 1, 0);
    }
    if (board[r][c] != '.') {
      return solveSudoku(board, r, c + 1);
    }

    for (int d = 0; d < 9; d++) {
      if (!check(r, c, d)) {
        continue;
      }
      board[r][c] = static_cast<char>(d + '1');
      row[r][d] = true;
      col[c][d] = true;
      square[3 * (r / 3) + c / 3][d] = true;
      if (solveSudoku(board, r, c + 1)) {
        return true;
      }
      board[r][c] = '.';
      row[r][d] = false;
      col[c][d] = false;
      square[3 * (r / 3) + c / 3][d] = false;
    }

    return false;
  }
};
