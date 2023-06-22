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
        int n =0;
        ListNode* count =head;
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode *prev = dummy,*curr=dummy, *nxt = dummy;
        while(count){
            n++;
            count = count->next;  
        }
        while(n>=k){
            curr = prev->next;
            nxt = curr->next;
            for(int i=1;i<k;i++){
                curr->next = nxt->next;
                nxt->next = prev->next;
                prev->next = nxt;
                nxt = curr->next;
            }
            prev = curr;
            n-=k;
        }
        return dummy->next;
    }
};