class Solution {
public:
    int longest_path = 0;
    void solve(TreeNode* root, int path, int curr_path_len)
    {
        if(!root) return ;
        curr_path_len++;
        longest_path = max(longest_path, curr_path_len); 
        if(path) 
        {
            solve( root->left, 0, curr_path_len);
            solve( root->right, 1, 0);   
        }
        else{    
            solve( root->left, 0, 0);   
            solve( root->right, 1, curr_path_len);
        }
    }
    int longestZigZag(TreeNode* root) {
	
        solve( root, 0, -1); 
        solve( root, 1, -1);
        return longest_path;
    }
};