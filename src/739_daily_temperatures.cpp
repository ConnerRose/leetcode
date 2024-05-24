#include <stack>
#include <vector>

class Solution {
 public:
  static auto dailyTemperatures(std::vector<int>& temperatures)
      -> std::vector<int> {
    int n = static_cast<int>(temperatures.size());
    std::vector<int> res(n, 0);
    std::stack<int> st;

    for (int i = n - 1; i >= 0; --i) {
      while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
        st.pop();
      }

      if (!st.empty()) {
        res[i] = st.top() - i;
      }

      st.push(i);
    }

    return res;
  }
};
