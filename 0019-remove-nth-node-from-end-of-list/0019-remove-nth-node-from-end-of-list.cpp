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
        ListNode* x=head;
        while(n){
            x=x->next;
            n--;
        }
        if(x==NULL) return head->next;
        ListNode* y=head;
        while(x){
            x = x->next;
            if(x!=NULL) y = y->next;
        }
        if(y->next && y->next->next) y->next = y->next->next;
        else y->next = NULL;

        return head;
    } 
};