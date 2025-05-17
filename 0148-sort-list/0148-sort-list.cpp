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

    ListNode* findMiddle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* mergeTwo(ListNode* l1, ListNode* l2){
        ListNode* newHead = NULL;
        ListNode* tail = newHead;

        while(l1 && l2){
            if(l1->val < l2->val){
                if(!newHead){
                     newHead = l1;
                     tail = newHead;
                }else{
                    tail->next = l1;
                    tail = l1;
                }
                l1 = l1->next;
            }else {
                if(!newHead){
                    newHead = l2;
                    tail = newHead;
                }else{
                    tail->next = l2;
                    tail = l2;
                }
                l2 = l2->next;
            }
        }

        while(l1){
            if(!newHead){
                newHead = l1;
                tail = newHead;
            } else {
                tail->next = l1;
                tail = l1;
            }
            l1 = l1->next;
        }

        while(l2){
            if(!newHead){
                newHead = l2;
                tail = newHead;
            } else {
                tail->next = l2;
                tail = l2;
            }
            l2 = l2->next;
        }

        return newHead;

    }

    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        
        ListNode* middle = findMiddle(head);
        ListNode* right = middle->next;
        middle->next = NULL;

        ListNode* left = head;

        left = sortList(left);
        right = sortList(right);

        return mergeTwo(left,right);
    }
};