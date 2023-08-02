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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int> , greater<int>> pq;
        for(auto x: lists){
            while(x){
                pq.push(x->val);
                x=x->next;
            }
        }

        ListNode* head = new ListNode;
        auto ans = head;

        while(!pq.empty()){
            ListNode* temp = new ListNode;
            temp->val = pq.top();
            pq.pop();
            ans->next = temp;
            ans = temp;
        }

        return head->next;
    }
};