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
    void reorderList(ListNode* head) {
        ListNode* mid = head;
        ListNode* scout = head;
        while(scout->next != nullptr && scout->next->next != nullptr){
            mid = mid->next;
            scout = scout->next->next; 
        }

        ListNode* curr = mid;
        ListNode* prev = nullptr; 
        ListNode* next = nullptr;

        while(curr != nullptr){
            next = curr->next; 
            curr->next = prev;
            prev = curr; 
            curr = next; 
        }

        ListNode* first = head;
        ListNode* second = prev; 
        ListNode* firstNext = nullptr;
        ListNode* secondNext = nullptr;

        while(first != nullptr && second != nullptr){
            firstNext = first->next;
            secondNext = second->next; 

            first->next = second;
            second->next = firstNext;

            first = firstNext;
            second = secondNext; 
        }
    }
};
