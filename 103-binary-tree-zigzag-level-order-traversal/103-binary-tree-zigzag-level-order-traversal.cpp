class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>>ans;
        
        if(root==NULL)
        {
            return ans;
        }
        
        queue<TreeNode*>q;
        q.push(root);
        
        bool toRight = true;
        
        while(!q.empty())
        {
            int size = q.size();
            vector<int>lvl(size);
            
            for(int i=0; i<size; i++)
            {
                int idx = toRight ? i : size - i - 1;
                
                TreeNode* node = q.front();
                q.pop();
                
                if(node->left!=NULL)
                {
                    q.push(node->left);
                }
                
                if(node->right!=NULL)
                {
                    q.push(node->right);
                }
                
                lvl[idx] = node->val;
            }
            
            toRight = !toRight;
            ans.push_back(lvl);
        }
        
        return ans;
        
    }
};