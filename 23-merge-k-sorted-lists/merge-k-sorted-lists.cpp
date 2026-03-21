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
class compare {
    public:
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
};
class Solution {
public:
   
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> minh;

        for(int i=0; i<lists.size(); i++){
            if(lists[i] != NULL)
                minh.push(lists[i]);
        }

        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        while(!minh.empty()){
            ListNode* temp = minh.top();
            minh.pop();
            tail->next = temp;
            tail= tail->next;

            if(temp->next != NULL){
                minh.push(temp->next);
            }
        }
        return dummy->next;
    }
};