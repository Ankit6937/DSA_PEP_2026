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
    TreeNode* solve(vector<int>& nums,int l,int r) {
        // find mid element-> (l+r)/2
        if(l>r) return NULL;
        int mid=(l+r)/2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left=solve(nums,l,mid-1);
        node->right=solve(nums,mid+1,r);
        return node;        
    }
    TreeNode* sortedArrayToBST(vector<int>&nums){
        int r=nums.size()-1;
        return solve(nums,0,r);

    }
};