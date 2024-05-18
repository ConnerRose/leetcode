class Solution {
  long long choose(int n, int k) {
    if (k == 0) {
      return 1;
    }
    return (n * choose(n - 1, k - 1)) / k;
  }

 public:
  int uniquePaths(int m, int n) { return choose(m + n - 2, m - 1); }
};
