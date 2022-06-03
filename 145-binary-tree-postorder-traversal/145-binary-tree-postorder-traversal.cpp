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

//Recursive
class Solution {
    // void rec(TreeNode *root, vector<int> &result){
    //    if(root!=NULL){
    //         rec(root->left,result);
    //         rec(root->right,result);
    //         result.push_back(root->val);
    //    }
    // }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
       
        if(root==NULL) return result;
        
        // rec(root,result);
        
        stack<TreeNode*> st;
        
        st.push(root);
        
        while(!st.empty()){
            int size=st.size();
            
            while(size-- >0){
                TreeNode* node=st.top();
                st.pop();
                
                result.push_back(node->val);
                
                if(node->left!=NULL)
                    st.push(node->left);
                
                if(node->right!=NULL)
                    st.push(node->right);
            }
        }
        reverse(result.begin(),result.end());
        return result;
    }
};