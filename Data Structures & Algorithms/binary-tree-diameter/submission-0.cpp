/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <vector>
#include <string>
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDiameter = 0;
        calculateDepth(root, maxDiameter);
        return maxDiameter;
    }
private:
    int calculateDepth(TreeNode *node, int &maxDiameter) {
    if (!node) {
      return 0;
    }
    int leftDepth = calculateDepth(node->left, maxDiameter);
    int rightDepth = calculateDepth(node->right, maxDiameter);
    maxDiameter = std::max(maxDiameter, leftDepth + rightDepth);
    return std::max(leftDepth, rightDepth) + 1;
  }
};
