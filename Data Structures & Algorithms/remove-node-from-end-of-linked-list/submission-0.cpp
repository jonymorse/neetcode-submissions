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

        /*
        n = 2
        n = 2 d,[1],2,3,4,5
        n = 1 d,1,[2],3,4,5
        n = 0 d,1,2,[3],4,5

         {d},1,2,[3],4,5
         d,{1},2,3,[4],5
         d,1,{2},3,4,[5]
         d,1,2,{3},4,5,[]

         n = 1
         d,[1]
         {d},1,[]

        */
        ListNode* dummy = new ListNode(0, head);
        ListNode* slow = dummy; 
        ListNode* fast = head;
        while(n != 0 && fast != nullptr){
            fast = fast->next; 
            n--;
        }

        while(fast != nullptr){
            slow = slow->next;
            fast = fast->next; 
        }

        ListNode* dlt = slow->next; //1
        ListNode* save = dlt->next; //nullptr
        slow->next = save; 

        return dummy->next;
        

    }
};
