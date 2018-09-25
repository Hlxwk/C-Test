/*
输入一颗二叉树的跟节点和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
(注意: 在返回值的list中，数组长度大的数组靠前)
*/
class Solution {
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        vector<vector<int>> ret;
        vector<int> trace;
        if(root)
            dfs(root,expectNumber,ret,trace);
        return ret;
    }
    void dfs(TreeNode* root,int s,vector<vector<int>> &ret,vector<int> &trace) {
        trace.push_back(root->val);
        if(!root->left&&!root->right) {
            if(s==root->val)
                ret.push_back(trace);
        }
        if(root->left)
            dfs(root->left,s-root->val,ret,trace);
        if(root->right)
            dfs(root->right,s-root->val,ret,trace);
        trace.pop_back();
    }
};