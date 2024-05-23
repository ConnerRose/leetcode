#include <algorithm>
#include <vector>

class Solution {
 public:
  static auto leastInterval(std::vector<char>& tasks, int n) -> int {
    std::vector<int> counter(26, 0);
    int maxFreq = 0;
    for (auto e : tasks) {
      ++counter[e - 'A'];
      maxFreq = std::max(maxFreq, counter[e - 'A']);
    }

    // Schedule first maxFreq - 1 occurrences of each task
    int res = (maxFreq - 1) * (n + 1);
    // Schedule last occurrence for tasks with maxFreq occurrences
    for (auto freq : counter) {
      if (freq == maxFreq) {
        ++res;
      }
    }
    return std::max(static_cast<int>(tasks.size()), res);
  }
};
