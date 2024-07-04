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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* p1=head;
        while (p1 != NULL && p1->next != NULL) {
            if (p1->next->val == 0) {
                if (p1->next->next == NULL) {
                    p1->next = NULL;
                } else {
                    p1 = p1->next;
                }
            } else {
                p1->val += p1->next->val; 
                p1->next = p1->next->next;
            }
        }

        return head;
    }
};