// Problem: 
// 从上往下打印出二叉树的每个节点，同层节点从左至右打印。

/*
 * This is a typical application of queue.
 * With the help of a queue, you can easily do this.
 */

#include <queue>
#include <vector>

using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> HierarchicalTraversal(TreeNode* root) {
        if (root == nullptr) { 
            // further error handle
            return vector<int>(); 
        }

        vector<int> ret;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            auto cur = q.front();
            // from left to right push the current
            // root's children to the queue
            if (cur -> left) q.push(cur -> left);
            if (cur -> right) q.push(cur -> right);
            ret.push_back(cur -> val);
            q.pop();
        }
        return ret;
    }
};
