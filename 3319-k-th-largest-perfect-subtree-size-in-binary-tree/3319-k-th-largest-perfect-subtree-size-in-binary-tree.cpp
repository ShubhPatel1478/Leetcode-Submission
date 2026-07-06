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
    vector<int> ans;
    struct Node {
        bool perfect;
        int height;
        int size;
    };
    Node dfs(TreeNode* root) {
        if(!root)
            return{true, 0, 0};
        Node L=dfs(root->left);
        Node R=dfs(root->right);
        if(L.perfect && R.perfect && L.height==R.height) {
            int sz = L.size+R.size+1;
            ans.push_back(sz);
            return {true,L.height+1,sz};
        }
        return {false, max(L.height,R.height)+1,0};
    }
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        dfs(root);
        sort(ans.begin(), ans.end(),greater<int>());
        if(k>ans.size()){
            return -1;
        }
        return ans[k - 1];
    }
};