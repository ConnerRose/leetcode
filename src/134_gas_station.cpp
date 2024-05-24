#include <vector>

class Solution {
 public:
  static auto canCompleteCircuit(const std::vector<int>& gas,
                                 const std::vector<int>& cost) -> int {
    int total_surplus = 0;
    int surplus = 0;
    size_t start = 0;

    for (size_t i = 0; i < gas.size(); i++) {
      total_surplus += gas[i] - cost[i];
      surplus += gas[i] - cost[i];
      if (surplus < 0) {
        surplus = 0;
        start = i + 1;
      }
    }
    return (total_surplus < 0) ? -1 : static_cast<int>(start);
  }
};
