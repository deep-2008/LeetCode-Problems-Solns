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
    int camFinder(TreeNode* root,int &camera){
        if(root==NULL)
            return 1;
        
        int lc=camFinder(root->left,camera);
        int rc = camFinder(root->right,camera);
        
        if(lc==-1 || rc==-1){
            camera++;
            return 0;
        }
        
        if(lc==0 || rc==0)
            return 1;
        
        return -1;
    }
public:
    int minCameraCover(TreeNode* root) {
        int camera=0;
        
        //camFinder(root,camera);
        
        if(camFinder(root,camera)==-1)
        camera++;
        
        return camera;
        
    }
};