// Problem:
// 从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。

/*
 * 1. use queue
 * 2. use recursion
 */

#include <iostream>
#include <vector>

using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<vector<int> > layerTraverse(TreeNode* root) {
        if (root == nullptr) return ret;
        build(root, 0); 
        return ret;
    }

    // recursion needs a member variable
    vector<vector<int> > ret;
    void build(TreeNode* p, int depth) {
        if (p == nullptr) return;

        if (ret.size() == depth)
            ret.push_back(vector<int>());
        ret[depth].push_back(p -> val); // use depth to track layer
        build(p -> left, depth + 1);
        build(p -> right, depth + 1);
    }

};
