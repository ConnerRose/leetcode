#include <string>

struct Node {
  Node* arr[26];
  bool is_word;
  Node() {
    is_word = false;
    for (auto& a : arr) {
      a = nullptr;
    }
  }
};

class Trie {
  Node* root;

 public:
  Trie() { this->root = new Node(); }

  void insert(std::string word) {
    Node* curr = this->root;
    for (char c : word) {
      int i = c - 'a';
      if (curr->arr[i] == nullptr) {
        curr->arr[i] = new Node();
      }
      curr = curr->arr[i];
    }
    curr->is_word = true;
  }

  bool search(std::string word, bool prefix = false) {
    Node* curr = this->root;
    for (char c : word) {
      int i = c - 'a';
      if (curr->arr[i] == nullptr) {
        return false;
      }
      curr = curr->arr[i];
    }
    return prefix ? true : curr->is_word;
  }

  bool startsWith(std::string prefix) { return this->search(prefix, true); }
};
