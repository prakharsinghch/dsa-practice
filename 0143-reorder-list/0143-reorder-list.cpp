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
    void reorderList(ListNode* head) {
        if(head == NULL || (!head->next) || (!head->next->next)) return;

        stack<ListNode*> s;
        int n= 0;
        ListNode* p =  head;
        while(p){
            s.push(p);
            n++;
            p = p->next;
        }

        p = head;
        for(int i=0;i<n/2;i++){
            ListNode* top = s.top();
            s.pop();
            top->next = p->next;
            p->next = top;
            p = p->next->next;
        }
        p->next =  NULL;
    }
};