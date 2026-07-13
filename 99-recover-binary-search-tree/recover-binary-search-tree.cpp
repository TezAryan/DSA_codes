/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* prev = NULL; 
    TreeNode* g1First = NULL;
    TreeNode* g1Sec = NULL;
    TreeNode* g2Sec = NULL;
    TreeNode* g2First = NULL;
    int g = 0; 

    void helper ( TreeNode* root) { 

        if( root == NULL) return; 

              helper(root -> left);

        if( prev == NULL) prev = root;
        else { 
            if( root -> val < prev -> val) { 
                if (g == 0) { 
                    g1First = prev; 
                    g1Sec = root;
                    g++;
                } else {
                    g2First = prev; 
                    g2Sec = root;
                    g++;
                }


            }

            prev = root;
          
        } 

              helper(root -> right);
    }

    void recoverTree(TreeNode* root) {

        helper ( root ) ; 

        if( g == 1) { 
            swap ( g1First->val , g1Sec->val);
        } else { 
            swap ( g1First->val , g2Sec->val);
        }
        
    }
};