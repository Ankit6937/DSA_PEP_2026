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
//  step1 -. find the node to be deleted by compariesons 
//  step2 -> restructure its childer while preseving BST order

class Solution {
public:

    // Find minimum element (Inorder Successor)
    TreeNode* inorderSuccessor(TreeNode* node){
        while(node->left != NULL){
            node = node->left;
        }
        return node;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {

        if(root == NULL) return NULL;

        if(key < root->val){
            root->left = deleteNode(root->left, key);
        }
        else if(key > root->val){
            root->right = deleteNode(root->right, key);
        }
        else{
            // Node found

            // Case 1 & 2: 0 or 1 child
            if(root->left == NULL){
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            else if(root->right == NULL){
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            // Case 3: Two children
            TreeNode* temp = inorderSuccessor(root->right);
            root->val = temp->val;
            root->right = deleteNode(root->right, temp->val);
        }

        return root;
    }
};
