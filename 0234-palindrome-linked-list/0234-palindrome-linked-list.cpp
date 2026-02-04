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
    ListNode* reverse(ListNode* head) {
        ListNode* prevNode = NULL;
        ListNode* currNode = head;
        ListNode* nextNode = NULL;

        while (currNode != NULL) {
            nextNode = currNode->next;
            currNode->next = prevNode;
            prevNode = currNode;
            currNode = nextNode;
        }
        return prevNode;   
    }

    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return true;

        ListNode* slow = head;
        ListNode* fast = head;   

        // find middle
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;          
            fast = fast->next->next;
        }

        // reverse second half
        slow = reverse(slow);   
        ListNode* p1 = head;
        ListNode* p2 = slow;

        // compare
        while (p2 != NULL) {
            if (p1->val != p2->val) {
                return false;   
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        return true;
    }
};
