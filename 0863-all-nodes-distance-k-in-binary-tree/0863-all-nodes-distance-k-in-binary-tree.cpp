/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
       vector<TreeNode*> parent(501,nullptr);
       queue<TreeNode*> q;
       q.push(root);
       
       while(!q.empty()){
     TreeNode* n=q.front();
     q.pop();
     if(n->left){
        q.push(n->left);
        parent[n->left->val]=n;
     }
     if(n->right){
        q.push(n->right);
        parent[n->right->val]=n;
     }
       }

       int dist=0;
       vector<bool> visited(501,false);
       q.push(target);
       visited[target->val]=true;
       
       while(dist<k && !q.empty()){
          int size=q.size();
          for(int i=0;i<size;i++){
            TreeNode* n=q.front();
            q.pop();
            if(n->left && !visited[n->left->val]){
                visited[n->left->val]=true;
                q.push(n->left);
            }
            if(n->right && !visited[n->right->val]){
                visited[n->right->val]=true;
                q.push(n->right);
            }
            if(parent[n->val] && !visited[parent[n->val]->val]){
                visited[parent[n->val]->val]=true;
                q.push(parent[n->val]);
            }
          }
         dist++;
       }

      int n=q.size();
       vector<int> ans(n);
       for(int i=0;i<n;i++){
        ans[i]=q.front()->val;
        q.pop();
       }
      return ans;
    }
};