#include <algorithm>
#include <numeric>
#include <vector>

class Solution {
 public:
  auto lexicographicallySmallestArray(std::vector<int>& nums, int limit)
      -> std::vector<int> {
    std::vector<std::pair<int, int>> indices(nums.size());
    for (int i = 0; i < nums.size(); ++i) {
      indices.emplace_back(nums[i], i);
    }
    std::ranges::sort(indices);
    std::vector<std::vector<int>> groups;
    for (int i = 0; i < nums.size(); ++i) {
      if (i == 0 || indices[i].first - indices[i - 1].first > limit) {
        groups.emplace_back(1, indices[i].second);
      } else {
        groups.back().push_back(indices[i].second);
      }
    }
    std::vector<int> res(nums.size());
    for (const auto& group : groups) {
      std::vector<int> sorted(group);
      std::ranges::sort(sorted);
      for (int i = 0; i < sorted.size(); ++i) {
        res[sorted[i]] = nums[group[i]];
      }
    }
    return res;
  }
};
