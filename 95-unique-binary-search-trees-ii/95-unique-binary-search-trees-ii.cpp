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
    vector<TreeNode*> solve(int sp,int ep){
        if(sp>ep){
            vector<TreeNode*> base;
            base.push_back(NULL);
            return base;
        }
        
        vector<TreeNode*> ans;
        for(int i=sp;i<=ep;i++){
            vector<TreeNode*> left=solve(sp,i-1);
            vector<TreeNode*> right=solve(i+1,ep);
            
            for(auto l:left){
                for(auto r:right){
                    TreeNode* root=new TreeNode(i);
                    root->left=l;
                    root->right=r;
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
      return solve(1,n);  
    }
};