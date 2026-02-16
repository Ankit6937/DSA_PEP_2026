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
        vector<int> result;
        if(root==NULL)return result;

        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int levelSize= q.size();
            int lastValue=0;
            for(int i = 0; i<levelSize;i++){
                TreeNode*frontNode=q.front();

                q.pop();
                lastValue = frontNode->val;
                if(frontNode->left)q.push(frontNode->left);
                if(frontNode->right) q.push(frontNode->right);
            }
            result.push_back(lastValue);
            
        }
        return result;
        
    }
};