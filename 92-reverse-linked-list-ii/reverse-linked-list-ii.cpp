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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL) return NULL;

        if(left == right) return head;

        ListNode* t = head;
        ListNode* before = NULL;
        int pos = 1;

        while( t != NULL) {
            if(pos < left) {
                before = t;
                t = t->next;
                pos++;
                continue;
            }     
        
        
        ListNode* curr = t;
        ListNode* prev = NULL;
        int times = right - left + 1;

        while ( times--) {
            ListNode* jump = curr ->next;
            curr -> next = prev;
            prev = curr;
            curr = jump;
        }

        t-> next = curr;
        if(before) {
        before -> next = prev;
        return head;
        } else {
        return prev; 
        }
        }  
        return head;
    }
};