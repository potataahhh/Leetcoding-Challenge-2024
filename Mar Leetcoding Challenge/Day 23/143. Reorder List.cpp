class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next)
            return;                             // No need to reorder for empty or single node list

        vector<ListNode*> arr;                  // to save address of all list nodes
        ListNode* temp = head;

        while (temp != nullptr) {
            arr.push_back(temp);
            temp = temp->next;
        }

        int i = 0, j = arr.size() - 1;
        while (i < j) {
            arr[i]->next = arr[j];
            i++;

            if (i == j) break;                  // Break if i and j meet

            arr[j]->next = arr[i];
            j--;
        }
        arr[i]->next = nullptr;
    }
};
