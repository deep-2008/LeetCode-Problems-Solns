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
//  */
// class Solution {
// public:
//     int widthOfBinaryTree(TreeNode* root) {
//         if(root==NULL)
//             return NULL;
//         queue<pair<TreeNode*,pair<long long int,int>>> q;
//         unordered_map<int,set<long long int>> mp;
        
//         q.push({root,{0,0}});
        
//         while(!q.empty()){
//             auto p=q.front();
//             q.pop();
            
//             TreeNode* node=p.first;
//            long long int i=p.second.first;
//             int lvl=p.second.second;
            
//             mp[lvl].insert(i);
            
//             if(node->left)
//                 q.push({node->left,{(1ll)*(2*i)+1,lvl+1}});
            
//             if(node->right)
//                 q.push({node->right,{(1ll)*(2*i)+2,lvl+1}});
                
//         }
        
//         int ans=0;
        
//         for(auto p:mp){
//            long long int mini=LONG_MAX;
//             long long int maxi=LONG_MIN;
            
//             for(auto q:p.second){
//                 mini=min(mini,q);
//                 maxi=max(maxi,q);
//             }
//             ans=max(ans,abs(maxi-mini));
//         }
        
//         return ans+1;
//     }
// };


class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        int res = 1;
        queue<pair<TreeNode*, int>> q;
        
        // I am using intialising list
        q.push({root, 0});      // also can use make_pair
        
        while(!q.empty())
        {
            int cnt = q.size();
            // start is the index of root node for first level
            int start = q.front().second;
            int end = q.back().second;
            
            res = max(res,end-start + 1);
            
            for(int i = 0; i <cnt; ++i)
            {
                pair<TreeNode*, int> p = q.front();
                // we will use it while inserting it children
                // left child will be 2 * idx + 1;
                // right chils will be 2 * idx + 2;
                int idx = p.second - start;
                
                q.pop();
                
                // if  left child exist
                if(p.first->left != NULL)
                    q.push({p.first->left, (long long)2 * idx + 1});
                
                // if right child exist
                if(p.first->right != NULL)
                    q.push({p.first->right, (long long) 2 * idx + 2});
            }
        }
        
        return res;
        
    }
};