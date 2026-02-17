class Solution {
public:
    vector<int> res;

    void solve(TreeNode* root){
        if(root == NULL) return;

        solve(root->left);
        res.push_back(root->val);
        solve(root->right);
    }
    
    bool findTarget(TreeNode* root, int k) {
        solve(root);

        int l = 0;
        int h = res.size() - 1;

        while(l < h){
            int sum = res[l] + res[h];

            if(sum == k) return true;
            else if(sum > k) h--;
            else l++;
        }

        return false;
    }
};
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
