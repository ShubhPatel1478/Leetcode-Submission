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
    TreeNode* findlastright(TreeNode* root){
        if(root->right==NULL){
            return root;
        }
        return findlastright(root->right);
    }
    TreeNode* helper(TreeNode* root){
        if(root->right==NULL){
            return root->left;
        }
        if(root->left==NULL){
            return root->right;
        }
        TreeNode* rightsub=root->right;
        TreeNode* lastright=findlastright(root->left);
        lastright->right=rightsub;
        return root->left;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* cur=root;
        if(cur==NULL){
            return cur;
        }
        if(cur->val==key){
            cur=helper(cur);
            return cur;
        }
        while(cur){
            if(cur->val>key){
                if(cur->left!=NULL && cur->left->val==key){
                    cur->left=helper(cur->left);
                    break;
                }
                else{
                    cur=cur->left;
                }
            }
            else{
                if(cur->right!=NULL && cur->right->val==key){
                    cur->right=helper(cur->right);
                    break;
                }
                else{
                    cur=cur->right;
                }
            }
        }
        return root;
    }
};