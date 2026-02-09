class Solution {
public:

    // 🔹 Find middle of linked list
    ListNode* getMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    // 🔹 Merge two sorted linked lists
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (l1 && l2) {
            if (l1->val <= l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        if (l1) tail->next = l1;
        if (l2) tail->next = l2;

        return dummy.next;
    }

    // 🔹 Main sort function (Merge Sort)
    ListNode* sortList(ListNode* head) {
        // base case
        if (head == NULL || head->next == NULL)
            return head;

        // find middle
        ListNode* mid = getMiddle(head);
        ListNode* right = mid->next;
        mid->next = NULL;

        // sort both halves
        ListNode* leftSorted = sortList(head);
        ListNode* rightSorted = sortList(right);

        // merge sorted lists
        return merge(leftSorted, rightSorted);
    }
};
