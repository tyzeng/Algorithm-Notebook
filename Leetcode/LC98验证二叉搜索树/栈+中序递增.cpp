/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;
         stack<TreeNode*> tNodeStack;
    tNodeStack.push(root);
    int max = (signed int)0x80000000;
    auto tn = root->left;
    bool have_set = false;
    while(!tNodeStack.empty() || tn != NULL)
    {
        while(tn != NULL)  //找到最左节点
        {
            tNodeStack.push(tn);
            tn = tn->left;
        }
        tn = tNodeStack.top(); tNodeStack.pop();
        if(have_set && tn->val <= max)
            return false;
        max = tn->val;
        have_set = true;
        tn = tn->right;
    }
    return true;
    }
};
