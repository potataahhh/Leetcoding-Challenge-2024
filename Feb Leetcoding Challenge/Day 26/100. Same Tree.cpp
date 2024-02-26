class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==0 && q==0) return true;
        if(p==0 || q==0) return false;
        if(p->val!=q->val) return false;
        return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
};
