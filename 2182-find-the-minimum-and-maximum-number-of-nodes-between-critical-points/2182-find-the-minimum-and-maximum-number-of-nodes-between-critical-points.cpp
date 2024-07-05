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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        // vector<int> ans;
        // int localmaxima=0;
        // int localminima=0;
        // if(!head||head->next==nullptr||head->next->next==nullptr){
        //     ans.push_back(-1);
        //     ans.push_back(-1);
        // }
        // ListNode* p1=head;
        // ListNode* p2=p1->next;
        // while(p1!=NULL && p2!=NULL){
        //     if(p2->val<p1->val && p2->val<p2->next->val){
        //         localminima+=p2->val;
        //         p1=p1->next;
        //         p2=p2->next;
        //     }
        //     if(p2->val>p1->val && p2->val>p2->next->val){
        //         localmaxima+=p2->val;
        //         p1=p1->next;
        //         p2=p2->next;
        //     }
        //}
        if (!head || !head->next || !head->next->next) return {-1, -1};

        unordered_map<int, int> criticalPoints;
        ListNode* p1 = head;
        ListNode* p2 = head->next;
        ListNode* p3 = head->next->next;
        int index = 1;
        int first = -1, last = -1, minDist = INT_MAX;

        while (p3) {
            if ((p2->val < p1->val && p2->val < p3->val) || (p2->val > p1->val && p2->val > p3->val)) {
                criticalPoints[index] = p2->val;
                if (first == -1) first = index;
                else minDist = min(minDist, index - last);
                last = index;
            }
            p1 = p2;
            p2 = p3;
            p3 = p3->next;
            index++;
        }

        if (criticalPoints.size() < 2) return {-1, -1};
        return {minDist, last - first};
    }
};