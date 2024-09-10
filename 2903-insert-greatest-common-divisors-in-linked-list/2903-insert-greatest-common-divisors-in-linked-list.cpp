// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
//     private:
//     int gcd(int a, int b) {
//         if (b == 0)
//             return a;
//         return gcd(b, a % b);
//     }
// public:
//     ListNode* insertGreatestCommonDivisors(ListNode* head) {
//         ListNode* p=head;
//         while(p!=nullptr && p->next!=nullptr){
//             ListNode* q=p->next;
//             int gcdVal=gcd(p->val,q->val);
//             ListNode* temp=new ListNode(gcdVal);
//             p->next=temp;
//             temp->next=q;
//         }
//         return head;
//     }
// };
#include <algorithm> // For std::min

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
private:
    // Iterative version of GCD to avoid recursion overhead
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (!head || !head->next) return head;  // No need to process if list has 0 or 1 nodes
        
        ListNode* p = head;
        
        while (p != nullptr && p->next != nullptr) {
            ListNode* q = p->next;
            int gcdVal = gcd(p->val, q->val);
            
            // Insert new node with gcd value between p and q
            ListNode* temp = new ListNode(gcdVal);
            p->next = temp;
            temp->next = q;
            
            // Move p to the next original node
            p = q;
        }
        
        return head;
    }
};
