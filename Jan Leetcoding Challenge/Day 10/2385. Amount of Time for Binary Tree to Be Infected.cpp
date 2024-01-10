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
    int res = INT_MIN; 

    int f(TreeNode* root,int start){
        if(root==NULL) return 0;

        int Left = f(root->left,start);
        int Right = f(root->right,start);

        if(root->val==start){
            res=max(Left,Right);
            return -1;
        }
        else if(Left>=0 && Right>=0){
            return max(Left,Right)+1;
        }
        else{
            int d = abs(Left)+abs(Right);
            res= max(res,d);
            return min(Left,Right)-1;
        }
        return 0;
    }

    int amountOfTime(TreeNode* root, int start) {
        
        f(root,start);
        return res;
    }
};
