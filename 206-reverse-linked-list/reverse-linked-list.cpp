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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }
        ListNode* temp;
        ListNode* prev = nullptr;
        ListNode* next = head;

        while (next != nullptr) {
            temp = next->next;
            next->next = prev; //reverses first thing
            prev = next;
            next = temp;
        }

        return prev;
    }

    
};