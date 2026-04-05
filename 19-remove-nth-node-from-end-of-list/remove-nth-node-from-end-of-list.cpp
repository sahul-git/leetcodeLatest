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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL) return NULL;
        ListNode* temp = head;
        int len = 0;

        while(temp){
            temp = temp->next;
            len++;
        }

        int count = len -n;
        ListNode* curr = head;
        if(count == 0) return curr->next;
        while(count > 1){
            curr = curr->next;
            count--;
        }

        curr->next = curr->next->next;
        return head;
    }
};