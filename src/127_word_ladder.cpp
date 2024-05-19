#include <algorithm>
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>

class Solution {
 public:
  int ladderLength(std::string begin_word, std::string end_word,
                   std::vector<std::string>& word_list) {
    if (std::find(word_list.begin(), word_list.end(), end_word) ==
        word_list.end()) {
      return 0;
    }

    std::unordered_set<std::string> dict(word_list.begin(), word_list.end());

    std::queue<std::string> q;
    q.push(begin_word);
    dict.erase(begin_word);

    int res = 1;
    while (!q.empty()) {
      int size = q.size();
      for (int i = 0; i < size; ++i) {
        std::string word = q.front();
        q.pop();
        dict.erase(word);
        if (word == end_word) {
          return res;
        }
        for (int j = 0; j < word.size(); ++j) {
          char init = word[j];
          for (char c = 'a'; c <= 'z'; ++c) {
            word[j] = c;
            if (dict.contains(word)) {
              q.push(word);
            }
          }
          word[j] = init;
        }
      }
      ++res;
    }

    return 0;
  }
};
