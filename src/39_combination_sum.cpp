#include <algorithm>
#include <vector>

using std::vector;

class Solution {
 public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    std::sort(candidates.begin(), candidates.end());
    vector<vector<int>> res;
    vector<int> curr;
    backtrack(res, curr, candidates, target, 0);
    return res;
  }

  void backtrack(vector<vector<int>>& res, vector<int>& curr,
                 vector<int>& candidates, int target, int start_idx) {
    if (target < 0) {
      return;
    }
    if (target == 0) {
      res.push_back(curr);
    }
    for (int i = start_idx; i < candidates.size(); ++i) {
      curr.push_back(candidates[i]);
      backtrack(res, curr, candidates, target - candidates[i], i);
      curr.pop_back();
    }
  }
};
