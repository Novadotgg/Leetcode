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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        // ListNode* p1=head;
        // int i=0;
        // while(p1->next){
        //     if(p1->val==nums[i]){
        //         if(p1==head){
        //             p1=p1->next;
        //             head=p1;
        //             i++;
        //         }
        //         p1=
        //     }
        // }
        sort(nums.begin(), nums.end());

        ListNode* dummy = new ListNode(0, head);  
        ListNode* p1 = dummy;

        while (p1->next) {
            
            if (binary_search(nums.begin(), nums.end(), p1->next->val)) {
                ListNode* toDelete = p1->next;
                p1->next = p1->next->next;
                delete toDelete;
            } else {
                p1 = p1->next;
            }
        }

        ListNode* newHead = dummy->next;
        delete dummy; 
        return newHead;
    }
};
void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "null" << endl;
}


ListNode* createList(const vector<int>& vec) {
    ListNode* dummy = new ListNode(0);
    ListNode* curr = dummy;
    for (int val : vec) {
        curr->next = new ListNode(val);
        curr = curr->next;
    }
    ListNode* head = dummy->next;
    delete dummy; 
    return head;
}