// base condition
// call the recursive function for left nodes
// check for nodes that are falling within the range
// call the recursive function for right nodes
// return the answer

class Solution {
public:
    int sum=0;
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root==NULL) return 0;
        rangeSumBST(root->left,low,high);
        if(root->val >= low && root->val <=high){
            sum+=root->val;
        }
        rangeSumBST(root->right,low,high);        
        return sum;
    }
};
