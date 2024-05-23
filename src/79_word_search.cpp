#include <string>
#include <vector>

const std::vector<int> dir = {0, 1, 0, -1, 0};

class Solution {
  auto search(std::vector<std::vector<char>>& board, const std::string& word,
              size_t idx, size_t i, size_t j) -> bool {

    if (idx == word.size()) {
      return true;
    }
    if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() ||
        board[i][j] != word[idx]) {
      return false;
    }
    board[i][j] -= 26;
    for (size_t k = 0; k < dir.size() - 1; ++k) {
      if (search(board, word, idx + 1, i + dir[k], j + dir[k + 1])) {
        return true;
      }
    }
    board[i][j] += 26;
    return false;
  }

 public:
  auto exist(std::vector<std::vector<char>>& board, const std::string& word)
      -> bool {
    for (size_t i = 0; i < board.size(); ++i) {
      for (size_t j = 0; j < board[0].size(); ++j) {
        if (search(board, word, 0, i, j)) {
          return true;
        }
      }
    }
    return false;
  }
};
