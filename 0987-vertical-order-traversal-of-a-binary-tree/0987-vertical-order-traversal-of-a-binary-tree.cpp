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
     
    vector<vector<int>> verticalTraversal(TreeNode* root) {
    
        vector<vector<int>> result;

        if(root == NULL) return result;
        
        // hd -> level -> multiset of values
        map<int, map<int, multiset<int>>> nodes;
        
        // node , horizontal distance , level
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});
        
        while(!q.empty()){
            
            auto temp = q.front();
            q.pop();

            TreeNode* curr = temp.first;
            int hd = temp.second.first;
            int level = temp.second.second;
            
            nodes[hd][level].insert(curr->val);

            if(curr->left){
                q.push({curr->left, {hd-1, level+1}});
            }
            if(curr->right){
                q.push({curr->right, {hd+1, level+1}});
            }
        }
        
        // Traverse map
        for(auto &i : nodes){
            
            vector<int> columnAns;
            
            for(auto &levelPair : i.second){
                for(auto value : levelPair.second){
                    columnAns.push_back(value);
                }
            }
            
            result.push_back(columnAns);
        }
        
        return result;
    }
};
