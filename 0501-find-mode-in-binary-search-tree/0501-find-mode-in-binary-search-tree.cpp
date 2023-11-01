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

    void solve(TreeNode* root, unordered_map<int, int> &mode){
        if(!root){
            return;
        }
        mode[root->val]++;
        //left
        solve(root->left, mode);
        //right
        solve(root->right, mode);

    }

    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        unordered_map<int, int> mode;
        solve(root, mode);
        int maxfreq=INT_MIN;
        for(auto x:mode){
            if(x.second>maxfreq){
                maxfreq=x.second;
            }
        }
        for(auto x:mode){
            if(x.second==maxfreq){
                ans.push_back(x.first);
            }
        }
        return ans;
    }
};