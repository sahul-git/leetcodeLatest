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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head->next == NULL || left == right) return head;

        ListNode* temp = head;
        ListNode* prev = NULL;
        ListNode* aft = NULL;
        ListNode* bef = head;
        ListNode* start = NULL;

        for(int i=0; i<left-1; i++){
            if( i == left - 2){
                bef = temp;
            }
            temp = temp->next;
        }

        start  = temp;
        for(int i=0; i<(right-left+1); i++){
            aft = temp->next;
            temp->next = prev;
            prev = temp;
            temp=aft;
        }

        start->next = aft;
        if(bef == start){
            head = prev;
            return head;
        }

        bef->next = prev;
        return head;
    }
};