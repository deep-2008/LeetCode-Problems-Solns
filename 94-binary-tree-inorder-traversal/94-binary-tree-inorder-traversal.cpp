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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        
        
        if(root==NULL) return ans;
        
        //MORRIS TRAVERSAL
//         TreeNode *curr=root;
//         while(curr!=NULL){
//             if(curr->left!=NULL){
//                TreeNode *temp=curr->left;
//                 TreeNode *tptr=curr->left;
                
//                 while(temp->right!=NULL)
//                     temp=temp->right;
//                 temp->right=curr;
//                 curr->left=NULL;
//                 curr=tptr;
//             }
//             else{
//                 ans.push_back(curr->val);
//                 curr=curr->right;
//             }
//         }
        
        stack<TreeNode*> st;
        TreeNode* node=root;
        
        while(1){
            if(node!=NULL){
                st.push(node);
                node=node->left;
            }
            
            else{
                if(st.empty())
                    break;
                node=st.top();
                st.pop();
                ans.push_back(node->val);
                node=node->right;
            }
        }
        
        return ans;
    }
};