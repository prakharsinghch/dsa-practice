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
    ListNode* partition(ListNode* head, int x) {
        
        if(head == NULL) return head;

        ListNode* s = new ListNode();
        ListNode* st = s;

        ListNode* l = new ListNode();
        ListNode* lt = l;

        ListNode* curr = head;

        while(curr){    

            if(curr->val < x){
                st->next = curr;
                st = st->next;
            }
            else{
                lt->next = curr;
                lt = lt->next;
            }

            curr = curr->next;
        }

        lt->next = NULL;
        st->next = l->next;

        return s->next;
    
    }
};