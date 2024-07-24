#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  auto hIndex(vector<int>& citations) -> int {
    int n = static_cast<int>(citations.size());
    sort(citations.begin(), citations.end());
    int res = 0;
    for (int i = 0; i < n; ++i) {
      res = max(res, min(n - i, citations[i]));
    }
    return res;
  }
};
