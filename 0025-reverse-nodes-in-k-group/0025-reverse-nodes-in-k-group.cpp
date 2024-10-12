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
        if (head == nullptr || k == 1) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* p = dummy;
        ListNode* q = head;
        ListNode* temp = nullptr;
        int count = 0;
        while (q != nullptr) {
            count++;
            q = q->next;
        }
        q = head;
        while (count >= k) {
            q = p->next; 
            temp = q->next; 
            for (int i = 1; i < k; i++) {
                q->next = temp->next;
                temp->next = p->next;
                p->next = temp;
                temp = q->next;
            }
            p = q; 
            count -= k;
        }

        return dummy->next;
    }
};
