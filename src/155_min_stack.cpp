#include <algorithm>
#include <stack>
#include <utility>

class MinStack {
  std::stack<std::pair<int, int>> stack;

 public:
  MinStack() {}

  void push(int val) {
    if (stack.empty()) {
      stack.push({val, val});
    } else {
      stack.push({val, std::min(val, stack.top().second)});
    }
  }

  void pop() { stack.pop(); }

  int top() { return stack.top().first; }

  int getMin() { return stack.top().second; }
};
