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
    void solve(TreeNode* root,TreeNode* prev,unordered_map<int,int>& mp,queue<TreeNode*> q,int left,vector<TreeNode*>& ans){
        if(root==NULL)
            return;
        
        int f=0;
        
        // if(mp.find(root->val)!=mp.end()){
        //     f=1;
        //     if(root->left){
        //         q.push(root->left);
        //         cout<<root->left->val<<" ";}
        //     if(root->right){
        //         q.push(root->right);
        //         cout<<root->right->val<<" ";}
        // }
        
        solve(root->left,root,mp,q,1,ans);
        solve(root->right,root,mp,q,0,ans);
        
         if(mp.find(root->val)!=mp.end()){
            f=1;
            if(root->right)
                ans.push_back(root->right);
                // cout<<root->left->val<<" ";}
            if(root->left)
                ans.push_back(root->left);
                // cout<<root->right->val<<" ";}
        }
        
        if(f==1){
            if(left)
                prev->left=NULL;
            else
                prev->right=NULL;
        }
    }
    
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        if(root==NULL)
            return {};
        
        unordered_map<int,int> mp;
        for(int i=0;i<to_delete.size();i++)
            mp[to_delete[i]]++;
        
       vector<TreeNode*> ans;
        queue<TreeNode*> q;
        // q.push(root);
        TreeNode* dummy=new TreeNode(-1);
        dummy->left=root;
        
        solve(dummy->left,dummy,mp,q,1,ans);
        if(dummy->left)
        ans.push_back(root);
        // while(!q.empty()){
        //     TreeNode* node=q.front();
        //     q.pop();
        //     ans.push_back(node);
        // }
        
        // reverse(ans.begin(),ans.end());
        
//         while(!q.empty()){
//             TreeNode* node=q.front();
//             q.pop();
            
//             if(mp.find(node->val)!=mp.end()){
//                 ans.push_back(NULL);
//             }
//             else
//                 ans.push_back(node);
            
//             if(node->left)
//                 q.push(node->left);
            
//             if(node->right)
//                 q.push(node->right);
//         }
        
        return ans;
    }
};