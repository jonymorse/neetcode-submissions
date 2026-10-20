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
    ListNode* merge(ListNode* first, ListNode* second){
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;
        while(first && second){
            if(first->val <= second->val){
                temp->next = first; 
                first = first->next;
            }
            else{
                temp->next = second; 
                second = second->next;
            }
            temp = temp->next; 
        }
        first ? temp->next = first : temp->next = second;
        return dummy->next; 
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        ListNode* merged = new ListNode(-1001);

        ListNode* temp = merged;
        for(int i = 0; i < lists.size(); i++){
            temp = merge(lists[i], temp);
            
        }
        return merged->next; 
    }
};
