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
    int solve(TreeNode* root,int &res){
        if(root==NULL)
            return 0;
        int l=solve(root->left,res);
        int r=solve(root->right,res);
        
        int temp=max(l,r)+1;
        res =max(res,l+r);
       // int ans=l+r+1;
        
        //res=max(res,ans);
        return temp;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int res=INT_MIN;
        
        solve(root,res);
        return res;
    }
};


/*class Solution {
public:
    int hight(TreeNode* root,int &ans){
        if(root == NULL){
            return 0;
        }
        int l = hight(root->left,ans);
        int r = hight(root->right,ans);
        ans = max(ans,l+r);
        return (max(l,r)+1);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int an = INT_MIN;
        int ht =  hight(root,an);
        return an;
    }
};*/