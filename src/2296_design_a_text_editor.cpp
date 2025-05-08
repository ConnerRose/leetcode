#include <algorithm>
#include <string>
#include <utility>
#include <vector>

class TextEditor {
  int left{0};
  int right{0};
  static constexpr int MAX_SIZE = 10;
  std::vector<char> buffer = std::vector<char>(MAX_SIZE, 0);

 public:
  auto addText(const std::string& text) -> void {
    if (left + right + text.size() > buffer.size()) {
      size_t prev_size = buffer.size();
      buffer.resize(std::max(left + right + text.size(), 2 * buffer.size()), 0);
      for (int i = 0; i < right; ++i) {
        std::swap(buffer[prev_size - 1 - i], buffer[buffer.size() - 1 - i]);
      }
    }
    for (char c : text) {
      buffer[left++] = c;
    }
  }

  auto deleteText(int k) -> int {
    int res = std::min(left, k);
    left -= res;
    return res;
  }

  auto cursorLeft(int k) -> std::string {
    while (k > 0 && left > 0) {
      std::swap(buffer[buffer.size() - 1 - right++], buffer[left-- - 1]);
      --k;
    }
    return {buffer.begin() + left - std::min(left, MAX_SIZE),
            buffer.begin() + left};
  }

  auto cursorRight(int k) -> std::string {
    while (k > 0 && right > 0) {
      std::swap(buffer[left++], buffer[buffer.size() - right--]);
      --k;
    }
    return {buffer.begin() + left - std::min(left, MAX_SIZE),
            buffer.begin() + left};
  }
};
