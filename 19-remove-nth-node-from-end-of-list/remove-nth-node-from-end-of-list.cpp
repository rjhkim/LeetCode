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
        3 steps
        1. initialize dummy node
        2. while loop to get position of right pointer
        3. while loop to move left and right pointer
            left pointer should be at position of one before the node to remove after right goes null
        */

        if (head->next == nullptr) {
            return nullptr;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while (n > 0) {
            fast = fast->next;
            n--;
        }

        //edge case - if the right pointer goes out of bounds, you skip head
        if (fast == nullptr) {
            return head->next;
        }

        while (fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }

        slow->next = slow->next->next;
        //line above skips the nth value from the end

        return head;
    }
};