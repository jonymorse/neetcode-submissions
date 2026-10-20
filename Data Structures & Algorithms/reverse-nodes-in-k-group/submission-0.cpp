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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);
        ListNode* prevTail = dummy; 
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        int kount = 0;

        while(curr != nullptr){
            ListNode* temp = curr;
            ListNode* tail = curr;
            while(temp != nullptr && kount < k){
                kount++;
                temp = temp->next;
            }
            if(kount == k){
                prev = temp;
                while(curr != temp){
                    next = curr->next;
                    curr->next = prev; 
                    prev = curr;
                    curr = next;
                }
                tail->next = curr; 
                prevTail->next = prev;
                prevTail = tail;
                kount = 0;
    
            }
            else{
                break;
            }
        }
        return dummy->next;
    }
};
