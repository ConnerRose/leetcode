#include <queue>
#include <vector>

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution1 {
  static auto merge2Lists(ListNode* l1, ListNode* l2) -> ListNode* {
    if (l1 == nullptr) {
      return l2;
    }
    if (l2 == nullptr) {
      return l1;
    }
    if (l1->val < l2->val) {
      l1->next = merge2Lists(l1->next, l2);
      return l1;
    }
    l2->next = merge2Lists(l1, l2->next);
    return l2;
  }

 public:
  static auto mergeKLists(std::vector<ListNode*>& lists) -> ListNode* {
    if (lists.empty()) {
      return nullptr;
    }
    size_t size = lists.size();
    while (size > 1) {
      for (size_t i = 0; i < size / 2; ++i) {
        lists[i] = merge2Lists(lists[i], lists[size - i - 1]);
      }
      size = (size + 1) / 2;
    }
    return lists.front();
  }
};

class Solution2 {
 public:
  static auto mergeKLists(std::vector<ListNode*>& lists) -> ListNode* {
    auto compare = [](ListNode* lhs, ListNode* rhs) {
      return lhs->val > rhs->val;
    };
    std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(compare)>
        pq;

    for (ListNode* node : lists) {
      if (node != nullptr) {
        pq.push(node);
      }
    }

    if (pq.empty()) {
      return nullptr;
    }

    ListNode* dummy = new ListNode();
    ListNode* curr = dummy;
    while (!pq.empty()) {
      ListNode* next = pq.top();
      pq.pop();

      curr->next = new ListNode(next->val);
      curr = curr->next;

      if (next->next != nullptr) {
        pq.push(next->next);
      }
    }

    return dummy->next;
  }
};
