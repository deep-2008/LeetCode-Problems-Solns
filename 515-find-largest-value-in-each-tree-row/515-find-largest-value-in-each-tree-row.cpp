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
//     vector<int> largestValues(TreeNode* root) {
//         if(root==NULL)
//             return {};
//         vector<int> ans;
//         queue<TreeNode*> q;
//         q.push(root);
        
//         while(!q.empty()){
//             int size=q.size();
//             int maxi=INT_MIN;
//             // vector<int> v;
            
//             while(size-->0){
//                 TreeNode* node =q.front();
//                 q.pop();
                
//                 maxi=max(maxi,node->val);
//                 // v.push_back(root->val);
                
//                 if(root->left)
//                     q.push(root->left);
//                 if(root->right)
//                     q.push(root->right);
//             }
//             // // sort(v.begin(),v.end());
//             // int temp=0;
//             // for(auto i:v)
//             //     temp=max(temp,i);
//             ans.push_back(maxi);
//         }
//         return ans;
//     }
    
    vector<int> largestValues(TreeNode* root) {
    //bfs 
    //level order traversal
    vector<int>res;
    if(root==NULL) return res;
    queue<TreeNode*>q;
    q.push(root);
    
    while(!q.empty()){
        int mi=INT_MIN;
        int x=q.size();
        for(int i=0;i<x;i++){
            if(q.front()->val>mi)
                mi=q.front()->val;
            if(q.front()->left)
            q.push(q.front()->left);
            
            if(q.front()->right)
                q.push(q.front()->right);
            q.pop();
                
        }
        res.push_back(mi);
    }
    return res;
}
};