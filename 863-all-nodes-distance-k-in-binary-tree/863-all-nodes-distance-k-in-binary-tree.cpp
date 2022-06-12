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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(root==NULL)
            return {};
        queue<TreeNode*> q;
        unordered_map<TreeNode*,TreeNode*> mp;
        
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            
            if(node->left){
                q.push(node->left);
                mp[node->left]=node;
            }
            
            if(node->right){
                q.push(node->right);
                mp[node->right]=node;
            }
        }
        
        queue<TreeNode*> q1;
        unordered_map<TreeNode*,int> vis;
        vector<int> ans;
        
        int dis=-1;
        
        q1.push(target);
        vis[target]=1;
        
        while(!q1.empty()){
            int size=q1.size();
            dis++;
            
            while(size-->0){
                TreeNode* node=q1.front();
                q1.pop();
                
                if(dis==k){
                    ans.push_back(node->val);
                }
                
                if(node->left && vis[node->left]==0){
                    q1.push(node->left);
                    vis[node->left]=1;
                }
                
                if(node->right && vis[node->right]==0){
                    q1.push(node->right);
                    vis[node->right]=1;
                }
                
                if(mp[node] && vis[mp[node]]==0){
                    q1.push(mp[node]);
                    vis[mp[node]]=1;
                }
            }
        }
        
        return ans;
        
    }
};