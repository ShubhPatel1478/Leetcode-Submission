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
    int d(unordered_map<TreeNode*,TreeNode*>&mpp,TreeNode* target){
         queue<TreeNode*>q;
         unordered_map<TreeNode*,int>vis;
         vis[target]++;
         q.push(target);
         int maxi=0;
         while(!q.empty()){
            int size=q.size();
            bool flag=false;
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->right!=NULL && vis.find(node->right)==vis.end()){
                    flag=true;
                    vis[node->right]++;
                    q.push(node->right);
                }
                if(node->left!=NULL && vis.find(node->left)==vis.end()){
                    flag=true;
                    vis[node->left]++;
                    q.push(node->left);
                }
                TreeNode* parent=mpp[node];
                if(parent!=NULL && vis.find(parent)==vis.end()){
                    vis[parent]++;
                    flag=true;
                    q.push(parent);
                }
            }
            if(flag){
                maxi++;
            }
         }
         return maxi;
    }
    TreeNode* f(TreeNode* root,int start,unordered_map<TreeNode*,TreeNode*>&mpp){
        TreeNode* res;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(node->val==start){
                res=node;
            }
            if(node->left!=NULL){
                mpp[node->left]=node;
                q.push({node->left});
            }
            if(node->right!=NULL){
                mpp[node->right]=node;
                q.push({node->right});
            }
        }
        return res;
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*>mpp;
        TreeNode*target=f(root,start,mpp);
        int ans=d(mpp,target);
        return ans;
    }
};