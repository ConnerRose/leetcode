#include <map>
#include <string>
#include <unordered_map>

using std::map;
using std::string;
using std::unordered_map;

class TimeMap {
  unordered_map<string, map<int, string>> map;

 public:
  TimeMap() {}

  void set(string key, string value, int timestamp) {
    map[key][timestamp] = value;
  }

  string get(string key, int timestamp) {
    if (!map.contains(key)) {
      return "";
    }
    auto iter = map[key].upper_bound(timestamp);
    return iter == map[key].begin() ? "" : (--iter)->second;
  }
};
