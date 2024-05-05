#include <algorithm>
#include <stack>
#include <utility>

using std::min;
using std::pair;
using std::stack;

class MinStack {
  stack<pair<int, int>> stack;

 public:
  MinStack() {}

  void push(int val) {
    if (stack.empty()) {
      stack.push({val, val});
    } else {
      stack.push({val, min(val, stack.top().second)});
    }
  }

  void pop() { stack.pop(); }

  int top() { return stack.top().first; }

  int getMin() { return stack.top().second; }
};
