/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> res(m,vector<int>(n,-1));
        int pos=0;
        int top=0;
        int bottom=m-1;
        int left=0;
        int right=n-1;

        while(top<=bottom && left<=right){
            if(pos==0){
                for(int i=left;head!=NULL && i<=right;i++){
                    res[top][i]= head->val;
                    head = head->next;
                }
                top++;
            }
            if(pos==1){
            for(int i = top;head!=NULL && i<=bottom;i++){
                res[i][right]=head->val;
                head=head->next;
                }
                right--;
            }
            if(pos==2){
                for(int i =right;head!=NULL && i>=left;i--){
                    res[bottom][i]=head->val;
                    head=head->next;
                }
                bottom--;
            }
            if(pos==3){
                for(int i=bottom;head!=NULL&& i>=top;i--){
                    res[i][left]=head->val;
                    head=head->next;
                }
                left++;
            }
            pos=(pos+1)%4;
        }
        return res;
    }
};
