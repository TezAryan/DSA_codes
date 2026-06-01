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
    TreeNode* ans = NULL; 
    int helper ( TreeNode* root , TreeNode* p , TreeNode* q) { 
        if( root == NULL ) return 0;

        int l = helper( root -> left , p , q);
        int r = helper( root -> right , p , q);

        int self = 0;

        if(root == p || root == q) 
        self = 1;

        int total = l + r + self;
        if(total == 2 && ans == NULL)
         ans = root;


         return total;
    }


    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        helper ( root , p , q ); 
        return ans; 
    }
};