#include <stack>
#include <unordered_map>

class FreqStack {
  std::unordered_map<int, int> freq;
  std::unordered_map<int, std::stack<int>> map;
  int max_freq = 0;

 public:
  auto push(int val) -> void {
    max_freq = std::max(max_freq, ++freq[val]);
    map[freq[val]].push(val);
  }

  auto pop() -> int {
    int x = map[max_freq].top();
    map[max_freq].pop();
    if (map[freq[x]].empty()) {
      --max_freq;
    }
    return x;
  }
};
