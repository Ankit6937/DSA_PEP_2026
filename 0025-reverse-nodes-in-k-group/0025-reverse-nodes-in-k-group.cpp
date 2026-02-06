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
        // Step 1: Check if k nodes exist
        ListNode* curr = head;
        int count = 0;

        while (curr != NULL && count < k) {
            curr = curr->next;
            count++;
        }

        // Step 2: If k nodes exist, reverse them
        if (count == k) {
            ListNode* prevNode = NULL;
            ListNode* currNode = head;
            ListNode* nextNode = NULL;
            int cnt = 0;

            while (cnt < k) {
                nextNode = currNode->next;
                currNode->next = prevNode;
                prevNode = currNode;
                currNode = nextNode;
                cnt++;
            }

            // Step 3: Recursively reverse remaining list
            head->next = reverseKGroup(currNode, k);

            // New head after reversing k nodes
            return prevNode;
        }

        // Step 4: If nodes < k, return as it is
        return head;
    }
};
