#include <functional>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using std::function;
using std::stack;
using std::string;
using std::unordered_map;
using std::vector;

class Solution {
 public:
  int evalRPN(vector<string>& tokens) {
    unordered_map<string, function<int(int, int)>> op = {
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
    for (string& s : tokens) {
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
