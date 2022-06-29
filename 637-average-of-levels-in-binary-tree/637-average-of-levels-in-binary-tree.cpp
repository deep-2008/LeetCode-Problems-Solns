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
    vector<double> averageOfLevels(TreeNode* root) {
         if(root==NULL)
         return {};
        
        vector<double> ans;
        queue<TreeNode*> q;
        // stack<vector<int>>st;
        q.push(root);
        
        while(!q.empty()){
            int size=q.size();
            // vector<int> temp;
            double x=0;
            int n=0;
            while(size-->0){
                TreeNode* node=q.front();
                q.pop();
                n++;
                
                // temp.push_back(node->val);
                
                x+= (double)node->val;
                
                if(node->left)
                    q.push(node->left);
                
                if(node->right)
                    q.push(node->right);
            }
            ans.push_back(x/n);
        }
        return ans;
    }
};