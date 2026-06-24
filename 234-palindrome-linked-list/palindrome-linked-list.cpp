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

ListNode* reverse ( ListNode* head) { 
      ListNode* prev = NULL;
        ListNode* curr = head; 

        while( curr ) { 
            ListNode* nextNode = curr -> next; 
            curr -> next = prev;
            prev = curr ; 
            curr  = nextNode;
        }

        return prev ; 
}

    bool isPalindrome(ListNode* head) {

        ListNode* slow = head; 
        ListNode* fast = head;

        if( head == nullptr && head-> next == nullptr) return true; 

        while ( fast != NULL && fast -> next != NULL) {
           
            slow = slow -> next;
            fast = fast -> next -> next;

        }

        ListNode* secondHalf = reverse(slow);

        ListNode* firstHalf = head ;

        while ( secondHalf) { 

            if(firstHalf -> val != secondHalf -> val) return false; 


            firstHalf = firstHalf -> next; 
            secondHalf = secondHalf -> next; 

        }

        return true;

      


        
    }
};