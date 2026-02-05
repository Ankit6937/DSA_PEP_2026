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
    int findLength(ListNode* head) {   // spelling fix
        int length = 0;
        ListNode* temp = head;

        while (temp != NULL) {
            length++;
            temp = temp->next;
        }
        return length;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = findLength(headA);
        int lenB = findLength(headB);

        ListNode* tempA = headA;
        ListNode* tempB = headB;

        int diffInLength = abs(lenA - lenB);

        // move pointer of longer list
        if (lenA > lenB) {
            while (diffInLength--) {
                tempA = tempA->next;
            }
        } else {
            while (diffInLength--) {
                tempB = tempB->next;
            }
        }

        // move both pointers together
        while (tempA != NULL && tempB != NULL) {
            if (tempA == tempB) {
                return tempA;   // intersection found
            }
            tempA = tempA->next;
            tempB = tempB->next;
        }

        return NULL; // no intersection
    }
};
