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

ListNode* reverseList(ListNode* head) {
        ListNode* temp = head;
        ListNode* prev = NULL;

    while(temp!=NULL){
        ListNode* front = temp->next;
        temp->next=prev;
        prev = temp;
        temp= front;
        
    }
    return prev; 
    }

    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next !=NULL && fast->next->next!=NULL){
            fast= fast->next->next;
            slow= slow->next;
        }
        ListNode* newHead = reverseList(slow->next);

        ListNode* first = head;
        ListNode* second = newHead;

        while(second!=NULL){
            if(first->val != second->val){
                reverseList(newHead);
                return false;
            }

            first=first->next;
            second=second->next;
        }
        reverseList(newHead);
        return true;

    }
};
