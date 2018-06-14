#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode *root, int sum) {
        if (root == NULL) {
            return {};
        }
        vector<int> path;
        vector<vector<int>> allPath;
        search(root, sum, path, allPath);
        return allPath;
    }

    void search(TreeNode *root, int sum, vector<int> &path, vector<vector<int>> &allPath) {
        if (root == NULL) {
            return;
        }
        path.push_back(root->val);
        if (root->left == NULL && root->right == NULL) {
            if (sum == root->val) {
                allPath.push_back(path);
            }
        }

        search(root->left, sum - root->val, path, allPath);
        search(root->right, sum - root->val, path, allPath);

        path.pop_back();
    }
};
