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
    TreeNode* search(TreeNode* original,TreeNode* cloned, TreeNode* target){
        if(!original)
            return NULL;
        if(original==target)
            return cloned;
        //search(original->left,cloned->left,target);
        //search(original->right,cloned->right,target);
        return max(search(original->left,cloned->left,target),search(original->right,cloned->right,target));
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
      // int t=target->val;
        
       return search(original,cloned,target);
      //  return cloned;
      //  return NULL;
    }
};