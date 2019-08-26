// Problem:
// 请实现一个函数按照之字形打印二叉树，
// 即第一行按照从左到右的顺序打印，
// 第二层按照从右至左的顺序打印，
// 第三行按照从左到右的顺序打印，其他行以此类推。

/*
 * Just like the layer traversal.
 * Judge the evenity of depth.
 */

#include <iostream>
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
    vector<vector<int> > zigzagTraverse(TreeNode* root) {
        if (!root) return ret;

        // else
        build(root, 0);
        return ret;
    }

    // member variable
    vector<vector<int> > ret;
    void build(TreeNode* p, int depth) {
        if (p == nullptr) return;

        // else
        if (ret.size() == depth)
            // increase the capacity
            ret.push_back(vector<int>());

        if (depth & 1)
            // if odd, insert from front
            ret[depth].insert(ret[depth].begin(), p -> val);
        else
            // o.w. push back
            ret[depth].push_back(p -> val);

        // two sub-problems
        build(p -> left, depth + 1);
        build(p -> right, depth + 1);
    }
};
