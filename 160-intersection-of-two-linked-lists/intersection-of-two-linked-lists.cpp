/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // ListNode* temp1 = headA;
        // while(temp1){
        //     ListNode* temp2 = headB;
        //     while(temp2){
        //         if(temp1 == temp2) return temp1;
        //         temp2 = temp2->next;
        //     }
        //     temp1= temp1->next;
        // }
        // return NULL;
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;
        int len1 = 0;
        int len2 = 0;

        while(temp1){
            temp1 = temp1->next;
            len1++;
        }
        while(temp2){
            temp2 = temp2->next;
            len2++;
        }

        int larger = 1;
        if(len1 <= len2) larger = 2;

        int count = abs(len1-len2);

        temp1 = headA;
        temp2 = headB;

        if(larger == 1){
            while(count--)
                temp1 = temp1->next;
        }else{
            while(count--)
                temp2 = temp2->next;
        }

        while(temp1 && temp2){
            if(temp1 == temp2) return temp2;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return NULL;

    }
};