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
class Solution{
public:
    TreeNode* f(vector<int>&preorder,int ps,int pe,vector<int>&inorder,int is,int ie,map<int,int>&mpp){
          if(ps>pe || is>ie){
            return NULL;
          }
          TreeNode* root=new TreeNode(preorder[ps]);
          int inroot=mpp[root->val];
          int left=inroot-is;
          root->left=f(preorder,ps+1,ps+left,inorder,is,inroot-1,mpp);
          root->right=f(preorder,ps+left+1,pe,inorder,inroot+1,ie,mpp);
          return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>mpp;
        for(int i=0;i<inorder.size();i++){
            mpp[inorder[i]]=i;
        }
        TreeNode* root=f(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mpp);
        return root;
    }
};