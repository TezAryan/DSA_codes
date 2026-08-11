/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
    //    unordered_map<Node* , Node*> mp;

    //     Node* curr = head ; 

    //     while( curr != NULL) { 

    //         Node* copy = new Node(curr -> val);
            
    //         mp[curr] = copy;

    //         curr = curr->next;
    //     }

    //     curr = head;


    //     while( curr != NULL) { 
    //         mp[curr]-> next = mp[curr -> next];
    //         mp[curr]->random = mp[curr -> random];
    //         curr = curr -> next ; 

    //      }

    //      return mp[head];




        if(head == NULL)
            return NULL;

        Node* curr = head;

        // Step 1: Create copies and insert them
        while(curr != NULL) {

            Node* copy = new Node(curr->val);

            copy->next = curr->next;
            curr->next = copy;

            curr = copy->next;
        }

        // Step 2: Set random pointers
        curr = head;

        while(curr != NULL) {

            if(curr->random != NULL) {
                curr->next->random = curr->random->next;
            }

            curr = curr->next->next;
        }

        // Step 3: Separate original and copied lists
        curr = head;

        Node* copyHead = head->next;

        while(curr != NULL) {

            Node* copy = curr->next;

            curr->next = copy->next;

            if(copy->next != NULL) {
                copy->next = copy->next->next;
            }

            curr = curr->next;
        }

        return copyHead;
    }
};

 