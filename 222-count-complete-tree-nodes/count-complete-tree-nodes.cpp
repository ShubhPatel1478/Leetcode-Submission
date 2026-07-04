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
    int fl(TreeNode *root){
        int c=0;
        while(root){
            c++;
            root=root->left;
        }
        return c;
    }
    int fr(TreeNode* root){
        int c=0;
        while(root){
            c++;
            root=root->right;
        }
        return c;
    }
    int countNodes(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int lh=fl(root);
        int rh=fr(root);
        if(lh==rh){
            return (1<<lh)-1;
        }
        return 1+countNodes(root->right)+countNodes(root->left);
    }
};