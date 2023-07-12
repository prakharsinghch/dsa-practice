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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head->next;
        ListNode *prev = head;
        if(fast == NULL) return NULL;
        while(fast && fast->next){
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
            
        }
        if(fast == NULL) prev->next = slow->next;
        else if(fast->next == NULL) slow->next = slow->next->next;
        return head;
    }
};