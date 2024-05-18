#include <functional>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
 public:
  int evalRPN(std::vector<std::string>& tokens) {
    std::unordered_map<std::string, std::function<int(int, int)>> op = {
        {"+",
         [](int lhs, int rhs) {
           return lhs + rhs;
         }},
        {"-",
         [](int lhs, int rhs) {
           return lhs - rhs;
         }},
        {"*",
         [](int lhs, int rhs) {
           return lhs * rhs;
         }},
        {"/", [](int lhs, int rhs) {
           return lhs / rhs;
         }}};
    std::stack<int> stack;
    for (std::string& s : tokens) {
      if (!op.count(s)) {
        stack.push(stoi(s));
      } else {
        int rhs = stack.top();
        stack.pop();
        int lhs = stack.top();
        stack.pop();
        stack.push(op[s](lhs, rhs));
      }
    }
    return stack.top();
  }
};
