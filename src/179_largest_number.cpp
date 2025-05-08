#include <algorithm>
#include <numeric>
#include <string>
#include <vector>

class Solution {
 public:
  constexpr static auto largestNumber(std::vector<int>& nums) -> std::string {
    std::sort(nums.begin(), nums.end(), [](const auto& num1, const auto& num2) {
      return std::to_string(num1) + std::to_string(num2) >
             std::to_string(num2) + std::to_string(num1);
    });
    return std::accumulate(nums.begin(), nums.end(), std::string{},
                           [](const std::string& acc, int num) {
                             return acc != "0" ? acc + std::to_string(num)
                                               : acc;
                           });
  }
};
