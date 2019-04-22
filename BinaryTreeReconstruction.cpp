#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void printer(TreeNode* root) {
    if (root == nullptr) return;
    
    queue<TreeNode*> todo;
    todo.push(root);
    while (!todo.empty()) {
        TreeNode* p = todo.front();
        if (p -> left)
            todo.push(p -> left);
        if (p -> right)
            todo.push(p -> right);
        cout << p -> val << ' ';
    }
}

TreeNode* build(vector<int>::iterator s1,
        vector<int>::iterator t1,
        vector<int>::iterator s2,
        vector<int>::iterator t2
        ) {
    // boundary case
    if (s2 >= t2) return nullptr;

    TreeNode a(*s1);
    TreeNode* root = &a;
    auto pos = std::find(s2, t2, *s1);
    int len1 = pos - s2;
    int len2 = t2 - (pos + 1);
    root -> left = build(s1+1,
            s1+1+len1,
            s2,
            s2+len1);
    root -> right = build(t1-len1,
            t1,
            t2-len2,
            t2);
    return root;
}

TreeNode* reconstruct(vector<int> pre, vector<int> in) {
    vector<int>::iterator s1 = pre.begin(),
        t1 = pre.end(),
        s2 = in.begin(),
        t2 = in.end();
    TreeNode* root = build(s1, t1, s2, t2);
    return root;
}

int main() {
    vector<int> pre = {1,2,4,7,3,5,6,8};
    vector<int> in = {4,7,2,1,5,3,8,6};
    TreeNode* root = reconstruct(pre, in);
    printer(root);
    return 0;
}
