/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
Node* copyRandomList(Node* head) {
    // TODO: Implement the deep copy logic here
    // 1. Use a hash map or interleaving technique to copy nodes and random pointers
    // 2. Return the head of the new list
    Node* og = new Node(0);
    og->next = head;
    og = og->next;

    Node* copyHead = new Node(0);
    Node* copy = copyHead;
    
    std::unordered_map<Node*,Node*> re;

    while(og != nullptr){
        
        //creates new node with the original value
        Node* newNode = new Node(og->val);
        //makes the copy value the same as og
        copy->next = newNode;

        re[og] = newNode;
        //moves to the next one
        copy = copy->next; 
        og = og->next; 
        
    }

    Node* temp = copyHead->next;
    while(head != nullptr){
        
        temp->random = re[head->random];
        head = head->next; 
        temp = temp->next; 
    }

    copyHead = copyHead->next;
    return copyHead;
}
};
