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
    vector<int> rightSideView(TreeNode* root) {
        vector<vector<int>>temp;
        vector<int>ans;
        queue<TreeNode*>q;
        if(root==NULL){
            return ans;
        }
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<int>s;
            for(int i=0;i<size;i++){
                TreeNode* t=q.front();
                q.pop();
                s.push_back(t->val);
                if(t->left!=NULL){
                    q.push(t->left);
                }
                if(t->right!=NULL){
                    q.push(t->right);
                }
            }
            temp.push_back(s);
        }
        for(int i=0;i<temp.size();i++){
            ans.push_back(temp[i].back());
        }
        return ans;
    }
};