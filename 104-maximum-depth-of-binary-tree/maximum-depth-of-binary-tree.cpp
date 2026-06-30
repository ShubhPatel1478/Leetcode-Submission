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
class Solution {
public:
    int f(TreeNode* node){
        if(node==NULL){
            return 0;
        }
        int lh=f(node->left);
        int rh=f(node->right);
        return 1+max(lh,rh);
    }
    int maxDepth(TreeNode* root) {
       return f(root);
    }
};