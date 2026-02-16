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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>result;
        if(root == NULL) return result;

        queue <TreeNode*> q;
        q.push(root);
        vector<int>levelElements;

        while(!q.empty()){
            int levelSize =q.size();
        vector<int> levelElements;

        for(int i =0; i<levelSize; i++){
            TreeNode* frontNode = q.front();
            q.pop();
            levelElements.push_back(frontNode->val);
            if(frontNode->left) q.push(frontNode->left);
            if(frontNode->right) q.push(frontNode->right);

        }
        result.push_back(levelElements);
            
            
        }
        return result;
        
    }
};