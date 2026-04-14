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
    class Node {
    public:
        int value;
        int row;
        ListNode* node;

        Node(int v, int r, ListNode* n) {
            value = v;
            row = r;
            node = n;
        }
    };

    struct Compare {
        bool operator()(const Node& a, const Node& b) {
            return a.value > b.value;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue<Node, vector<Node>, Compare> pq;

        for (int i = 0; i < lists.size(); i++) {
            if (lists[i]) {
                pq.push(Node(lists[i]->val, i, lists[i]));
            }
        }

        ListNode* head = NULL;
        ListNode* last = NULL ;

            while (!pq.empty()) {
            Node curr = pq.top();
            pq.pop();

            if (head == NULL) {
                head = curr.node;
                last = curr.node;

            } else {
                last->next = curr.node;
                last = last->next;
            }

            if (curr.node->next) {
                pq.push(Node(curr.node->next->val, curr.row, curr.node->next));
            }
        }
        return head;
    }
};