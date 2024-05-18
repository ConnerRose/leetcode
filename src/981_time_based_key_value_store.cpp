#include <map>
#include <string>
#include <unordered_map>

class TimeMap {
  std::unordered_map<std::string, std::map<int, std::string>> map;

 public:
  TimeMap() {}

  void set(std::string key, std::string value, int timestamp) {
    map[key][timestamp] = value;
  }

  std::string get(std::string key, int timestamp) {
    if (!map.contains(key)) {
      return "";
    }
    auto iter = map[key].upper_bound(timestamp);
    return iter == map[key].begin() ? "" : (--iter)->second;
  }
};
