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
        Node* curr=head;

        while(curr!= NULL){
            Node* dummy = new Node(curr->val);
            dummy->next = curr->next;
            curr->next = dummy;
            curr = dummy->next;
        }
        curr=head;
        while(curr !=NULL){
            if(curr-> random!=NULL){
                curr->next->random = curr->random->next;
            } 
            curr = curr->next->next;
        }

        Node* dummy = new Node(0);
        Node*tail= dummy;

        curr=head;
        while(curr!=NULL){
            Node* copyNode = curr->next;
            curr->next = copyNode->next;

            tail->next = copyNode;
            tail = tail->next;
            curr= curr->next;
        }
        return dummy->next;

        
    }
};