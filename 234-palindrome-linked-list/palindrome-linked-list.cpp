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
    ListNode* reverseList(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(curr){
            ListNode* after = curr->next;
            curr->next = prev;
            prev = curr;
            curr = after;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next==NULL) return true;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* head1 = reverseList(slow->next);
        while(head && head1){
            if(head->val!=head1->val) return false;
            head = head->next;
            head1 = head1->next;
        }
        return true;
    }
};