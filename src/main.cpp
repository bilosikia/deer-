
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
  
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if(n <= 0) {
            return std::vector<TreeNode *>();
        }

        std::vector<std::vector<std::vector<TreeNode *>>> dp;
        for(int i = 0; i <= n; ++i) {
            dp.push_back(std::vector<std::vector<TreeNode *>>());
            for(int j = 0; j <= n; ++j) {
                dp[i].push_back(std::vector<TreeNode *>());
            }
        }
        generate(dp, n);
        return dp[1 - 1][n - 1];
    }

    void generate(std::vector<std::vector<std::vector<TreeNode *>>> &dp, int n) {
        for(int len = 0; len < n; ++len) {
            for(int i = 1; i + len <= n; ++i) {
                
                for(int j = i; j <= i + len; ++j) {
                    auto lefts = i > j -1 ? std::vector<TreeNode *>{nullptr} : dp[i - 1][j - 1 - 1];
                    auto rights = j + 1 > i + len ? std::vector<TreeNode *>{nullptr} : dp[j + 1 -1][i + len -1];
                    for(auto l : lefts) {
                        for(auto r : rights) {
                            TreeNode *node  = new TreeNode(j);
                            node->left = l;
                            node->right = r;
                            dp[i - 1][i + len - 1].push_back(node);
                        }
                    }
                }
            }
        }
    }
};

int main() {
    Solution s;
    s.generateTrees(3);
    return 0;
}
