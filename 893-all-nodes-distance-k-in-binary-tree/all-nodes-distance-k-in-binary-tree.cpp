/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
        vector<int>ans ; 
        unordered_set<TreeNode*> visited;
        unordered_map<TreeNode* , TreeNode*> parent;

        void makeparent(TreeNode* root , TreeNode* par) { 

            if(root == NULL) return;

            parent[root] = par;

            makeparent( root -> left , root);
            makeparent(root->right , root);

        }


        void find(TreeNode* target , int k) { 

            if( target == NULL || visited.count(target)) {
                return;
            }

            visited.insert(target);

            if( k == 0) { 
                ans.push_back(target->val);
                return;
            }

            find( target-> left , k-1);
            find(target -> right , k-1);
            find(parent[target] , k-1);

        }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        makeparent( root , root);

        find( target , k) ; 

        return ans;
    }
};