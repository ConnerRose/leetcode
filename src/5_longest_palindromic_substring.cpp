#include <algorithm>
#include <string>
#include <vector>

using std::max;
using std::min;
using std::string;
using std::vector;

class Solution {
  vector<int> manacher_odd(string s) {
    int n = s.size();
    s = "$" + s + "^";
    vector<int> p(n + 2);
    int l = 1, r = 1;
    for (int i = 1; i <= n; i++) {
      p[i] = max(0, min(r - i, p[l + (r - i)]));
      while (s[i - p[i]] == s[i + p[i]]) {
        p[i]++;
      }
      if (i + p[i] > r) {
        l = i - p[i], r = i + p[i];
      }
    }
    return std::move(vector<int>(p.begin() + 1, p.end() - 1));
  }

  vector<int> manacher(string s) {

    string t = "#";
    for (auto c : s) {
      t += c + string("#");
    }
    auto res = manacher_odd(t + "#");
    vector<int> temp;
    for (int i = 1; i < res.size() - 1; i += 2) {
      temp.push_back(res[i] / 2);
    }
    return temp;
  }

 public:
  string longestPalindrome(string s) {
    vector<int> radii = manacher(s);
    string res = s.substr(0, 1);
    int max_length = 1;
    for (int i = 0; i < radii.size(); ++i) {
      if (radii[i] > max_length) {
        res = s.substr(i - radii[i], radii[i] * 2 + 1);
        max_length = radii[i];
      }
    }
    return res;
  }
};
