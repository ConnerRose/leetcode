#include <string>
#include <vector>

class Solution {
 public:
  int calculate(std::string s) {
    int res = 0;
    std::vector<bool> sign(2, true);
    for (int i = 0; i < s.size(); ++i) {
      char c = s[i];
      if (c >= '0') {
        int num = 0;
        while (i < s.size() && s[i] >= '0') {
          num = num * 10 + s[i++] - '0';
        }
        res += sign.back() ? num : -num;
        sign.pop_back();
        --i;
      } else if (c == ')') {
        sign.pop_back();
      } else if (c == '+') {
        sign.push_back(sign.back());
      } else if (c == '-') {
        sign.push_back(!sign.back());
      }
    }
    return res;
  }
};
