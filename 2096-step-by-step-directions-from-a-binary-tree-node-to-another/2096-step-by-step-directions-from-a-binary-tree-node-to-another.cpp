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
    TreeNode* LCA(TreeNode* root,int startValue,int destValue){
        if(root==NULL || root->val==startValue || root->val==destValue)
            return root;
        
        TreeNode* l=LCA(root->left,startValue,destValue);
        TreeNode* r=LCA(root->right,startValue,destValue);
        
        if(l==NULL)
            return r;
        
        if(r==NULL)
            return l;
        
        return root;
    }
    
    bool shortestPath(TreeNode* node,int key,string &s,char dir){
        if(node==NULL){
            // s.pop_back();
            return 0;
        }
        
        if(node->val==key){
            s.push_back(dir);
            return 1;
        }
        
        s.push_back(dir);
        // cout<<s<<" ";
        
        if(shortestPath(node->left,key,s,'L')){
            return 1;
            // s.pop_back();
        }
        
        if(shortestPath(node->right,key,s,'R')){
            return 1;
            // s.pop_back();
        }
        s.pop_back();
        return 0;
    }
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        if(root==NULL)
            return {};
        
        TreeNode* node=LCA(root,startValue,destValue);
        string start,end;
        // cout<<node->val;
        
        shortestPath(node,startValue,start,'-1');
        // cout<<start<<endl;
        shortestPath(node,destValue,end,'-1');
        // cout<<end<<endl;
        
        if(start.size()==0)
            return end;
        
        string ans;
        for(int i=1;i<start.size();i++){
            ans+='U';
        }
        
         for(int i=1;i<end.size();i++){
            ans+=end[i];
        }
        return ans;
    }
};