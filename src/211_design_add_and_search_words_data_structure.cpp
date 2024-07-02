#include <string>
#include <vector>

class WordDictionary {
  std::vector<WordDictionary*> children;
  bool isEndOfWord{};

 public:
  WordDictionary() { children = std::vector<WordDictionary*>(26, nullptr); }

  auto addWord(const std::string& word) -> void {
    WordDictionary* curr = this;
    for (char c : word) {
      if (curr->children[c - 'a'] == nullptr) {
        curr->children[c - 'a'] = new WordDictionary();
      }
      curr = curr->children[c - 'a'];
    }
    curr->isEndOfWord = true;
  }

  auto search(std::string word) -> bool {
    WordDictionary* curr = this;
    for (size_t i = 0; i < word.length(); ++i) {
      char c = word[i];
      if (c == '.') {
        for (auto child : curr->children) {
          if ((child != nullptr) && child->search(word.substr(i + 1))) {
            return true;
          }
        }
        return false;
      }
      if (curr->children[c - 'a'] == nullptr) {
        return false;
      }
      curr = curr->children[c - 'a'];
    }
    return (curr != nullptr) && curr->isEndOfWord;
  }
};
