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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head->next->next == NULL) return {-1, -1};
        vector<int> range;
        
        ListNode* temp = head;
        while(temp){
            range.push_back(0);
            temp = temp->next;
        }
        int counter = 1;
        temp = head;
        ListNode* prev = temp;
        temp = temp->next;
        vector<ListNode*> vec;

        while(temp->next){
            if(temp->val > prev->val && temp->val > temp->next->val){
                range[counter] = 1;
                vec.push_back(temp);
            }else if(temp->val < prev->val && temp->val < temp->next->val){
                range[counter] = 1;
                vec.push_back(temp);
            }
            counter++;
            prev = temp;
            temp = temp->next;
            
        }
        if(vec.size() < 2) return {-1, -1};

        int least = -1;
        for(int i= 0; i<range.size(); i++){
            if(range[i] == 1){
                least = i;
                break;
            }
        }
        int latest = -1;
        int maxi = -1;
        int minDist = INT_MAX;
        for(int i=0; i<range.size(); i++){
            if(range[i] == 1){
                if(latest != -1){
                    minDist = min(minDist, i-latest);
                }
                latest = i;
                maxi  = i;
            }   
        }
        return {minDist, maxi-least};
    }
};