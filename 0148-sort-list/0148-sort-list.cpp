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
    ListNode* sortList(ListNode* head) {
        if(head == NULL) return head;
        ListNode* n = head;
        vector<int> x; 
        while(n != NULL){
            x.push_back(n->val);
            n = n->next;
        }
        sort(x.begin(),x.end());
        ListNode* res = new ListNode();
        ListNode* ans = new ListNode();
        res = ans;
        for(int i= 0 ; i <x.size();i++){
            ListNode* l = new ListNode();
            l->val = x[i];
            ans->next = l;
            ans = ans->next;
        }
        return res->next;
    }
};