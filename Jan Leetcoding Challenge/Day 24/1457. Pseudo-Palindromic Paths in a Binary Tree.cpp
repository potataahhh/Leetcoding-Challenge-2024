

class Solution {
public:

    int res=0;

    void f(TreeNode* root,vector<int> &count){
        if(root==NULL) return;
        count[root->val]++;

        if(root->left==NULL && root->right==NULL){
            int odd=0;

            for(int i=1;i<=9;i++){
                if(count[i]%2!=0){
                    odd++;
                }
            }

            if(odd<=1){
                res++;
            }
        }

        f(root->left,count);
        f(root->right,count);

        count[root->val]--;
    }

    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> count(10,0);
        f(root,count);
        return res;
    }
};
