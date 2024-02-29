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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        bool even = true;

        while(!q.empty()){
            int prev;
            int n = q.size();

            if(even)
                prev = INT_MIN;
            else
                prev = INT_MAX;

            while(n--){
                TreeNode* temp = q.front();
                q.pop();

                if(even && (temp->val %2==0 || temp->val <= prev)){
                    return false;
                }

                if(!even && (temp->val%2 !=0 || temp->val >= prev)){
                    return false;
                }
            prev = temp->val;

            if(temp->left)
                q.push(temp->left);

            if(temp->right)
                q.push(temp->right);

            }
            even = !even;
        }
        return true;
    }
};
