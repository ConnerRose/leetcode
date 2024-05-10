#include <string>

using std::string;

class Solution {
 public:
  int myAtoi(string str) {
    int sign = 1, res = 0, i = 0;
    while (str[i] == ' ') {
      i++;
    }
    if (str[i] == '-' || str[i] == '+') {
      sign = str[i++] == '-' ? -1 : 1;
    }
    while ('0' <= str[i] && str[i] <= '9') {
      if (res > INT_MAX / 10 || (res == INT_MAX / 10 && str[i] - '0' > 7)) {
        if (sign == 1) {
          return INT_MAX;
        } else {
          return INT_MIN;
        }
      }
      res = 10 * res + (str[i++] - '0');
    }
    return res * sign;
  }
};
