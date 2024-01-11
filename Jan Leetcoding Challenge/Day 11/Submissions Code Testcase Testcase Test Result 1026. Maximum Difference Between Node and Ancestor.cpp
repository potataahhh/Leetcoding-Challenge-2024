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

    int f(TreeNode* root,int mini,int maxi){
        if(root==NULL){
            return abs(mini-maxi);
        }

        mini = min(mini,root->val);
        maxi=max(maxi,root->val);

        int Left = f(root->left,mini,maxi);
        int Right = f(root->right,mini,maxi);

        return max(Left,Right);
    }

    int maxAncestorDiff(TreeNode* root) {
       return f(root,root->val,root->val);
    }
};
