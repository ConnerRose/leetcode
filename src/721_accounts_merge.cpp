#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
  // Find parent with path compression
  int find(int parent, std::vector<int>& parents) {
    while (parent != parents[parent]) {
      parent = parents[parent];
    }
    return parent;
  }

 public:
  std::vector<std::vector<std::string>> accountsMerge(
      std::vector<std::vector<std::string>>& accounts) {
    std::vector<int> parents(accounts.size(), 0);
    std::unordered_map<std::string, int> email_to_account;

    for (int account = 0; account < accounts.size(); ++account) {
      // Every element is initially its own parent
      parents[account] = account;
      for (int j = 1; j < accounts[account].size(); ++j) {
        const std::string& email = accounts[account][j];
        auto iter = email_to_account.find(email);
        if (iter != email_to_account.end()) {
          // If we've already encountered this email,
          // set this email's ancestor account to the current account
          parents[find(iter->second, parents)] = account;
        }
        email_to_account[email] = account;
      }
    }

    std::unordered_map<int, int> account_to_idx;
    std::vector<std::vector<std::string>> res;
    for (const auto& [email, account] : email_to_account) {
      int parent = find(account, parents);
      auto iter = account_to_idx.find(parent);
      int idx;
      if (iter != account_to_idx.end()) {
        idx = iter->second;
      } else {
        idx = res.size();
        account_to_idx[parent] = idx;
        res.emplace_back(1, accounts[account][0]);
      }
      res[idx].push_back(email);
    }

    for (std::vector<std::string>& emails : res) {
      sort(emails.begin() + 1, emails.end());
    }

    return res;
  }
};
