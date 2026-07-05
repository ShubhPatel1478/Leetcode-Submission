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
    TreeNode* f(vector<int>&inorder,int is,int ie,vector<int>&postorder,int ps,int pe,map<int,int>&mpp){
        if(ps>pe || is>ie){
            return NULL;
        }
        TreeNode* root=new TreeNode(postorder[pe]);
        int inroot=mpp[postorder[pe]];
        int left=inroot-is;
        root->left=f(inorder,is,inroot-1,postorder,ps,ps+left-1,mpp);
        root->right=f(inorder,inroot+1,ie,postorder,ps+left,pe-1,mpp);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int>mpp;
        for(int i=0;i<inorder.size();i++){
            mpp[inorder[i]]=i;
        }
        TreeNode* root=f(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,mpp);
        return root;
    }
};