class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> l_nodes,r_nodes;
        l_nodes.push(root->left);
        r_nodes.push(root->right);
        while(l_nodes.size() !=0){
            if(l_nodes.front() == NULL and r_nodes.front() == NULL){
                l_nodes.pop();
                r_nodes.pop();
                continue;
            }
            if(l_nodes.front() == NULL or r_nodes.front() == NULL)    return 0;
            int n=l_nodes.size();
            int i=0;
            for(int i=0;i<n;i++){
                TreeNode* left = l_nodes.front();
                l_nodes.pop();
                TreeNode* right = r_nodes.front();
                r_nodes.pop();
                if(left == NULL and right == NULL)  continue;
                if(left == NULL or right == NULL)   return 0;    
                if(left->val!=right->val) return 0;
                l_nodes.push(left->left);
                l_nodes.push(left->right);
                r_nodes.push(right->right);
                r_nodes.push(right->left);
            }          
        }
        return 1; 
    }
};