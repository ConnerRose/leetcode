#include <vector>

template <class T>
class CircularBuffer {
  std::vector<T> buffer;
  size_t head{0};
  size_t tail{0};
  size_t capacity;

 public:
  CircularBuffer(size_t capacity) : capacity(capacity) {
    buffer = std::vector<T>(capacity);
  }

  auto push(T x) -> void {
    buffer[head++] = x;
    head %= capacity;
  }

  auto pop() -> T {
    T res = buffer[tail++];
    tail %= capacity;
    return res;
  }

  auto empty() -> bool { return head == tail; }
};

class Solution {
 public:
  bool canFinish(int num_courses,
                 std::vector<std::vector<int>>& prerequisites) {
    std::vector<std::vector<int>> adj;
    std::vector<int> deg;

    for (const auto& pair : prerequisites) {
      adj[pair[1]].push_back(pair[0]);
      ++deg[pair[1]];
    }

    CircularBuffer<int> s(num_courses);
    for (int i = 0; i < num_courses; ++i) {
      if (deg[i] == 0) {
        s.push(i);
      }
    }

    size_t edges = prerequisites.size();
    while (!s.empty()) {
      int n = s.pop();
      for (int m : adj[n]) {
        if (--deg[m] == 0) {
          s.push(m);
        }
        --edges;
      }
    }
    return edges == 0;
  }
};
