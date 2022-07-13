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
    vector<int> largestValues(TreeNode* root) {
        if(root==NULL)
            return {};
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int size=q.size();
            int maxi=INT_MIN;
            // vector<int> v;
            
            while(size-->0){
                TreeNode* node =q.front();
                q.pop();
                
                maxi=max(maxi,node->val);
                // v.push_back(root->val);
                
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            // // sort(v.begin(),v.end());
            // int temp=0;
            // for(auto i:v)
            //     temp=max(temp,i);
            ans.push_back(maxi);
        }
        return ans;
    }
};