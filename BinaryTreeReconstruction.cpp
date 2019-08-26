// 输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
// 假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
// 例如输入前序遍历序列 {1,2,4,7,3,5,6,8}
// 和中序遍历序列 {4,7,2,1,5,3,8,6}，则重建二叉树并返回。

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

void PreorderTranverse(TreeNode* root)
{
  if (root == nullptr) return;
  cout << root->val << " ";
  PreorderTranverse(root->left);
  PreorderTranverse(root->right);
}

void InorderTranverse(TreeNode* root)
{
  if (root == nullptr) return;
  InorderTranverse(root->left);
  cout << root->val << " ";
  InorderTranverse(root->right);
}

class Solution
{
public:
  TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> in)
  {
    if (pre.size() != in.size()) return nullptr;
    if (pre.size() < 1) return nullptr;

    preorder_ = pre;
    inorder_ = in;
    
    return build(0, preorder_.size(), 0, inorder_.size());
  }

private:
  /**
   * - pb: preorder begin index
   * - pe: preorder end index (exclude)
   * - ib: inorder begin index
   * - ie: inorder end index (exclude)
   */
  TreeNode* build(int pb, int pe, int ib, int ie)
  {
    if (pe - pb < 1)
      return nullptr;
    // pe - pb >= 1 o.w.

    TreeNode* root = new TreeNode(preorder_[pb]); 
    
    int pos = find_in(ib, ie, preorder_[pb]);
    // compute left-part
    int lpb = pb + 1;
    int lpe = lpb + (pos - ib);
    int lib = ib;
    int lie = pos;
    // compute right-part
    int rpb = lpe;
    int rpe = pe;
    int rib = pos + 1;
    int rie = ie;
    // recursive
    root->left = build(lpb, lpe, lib, lie);
    root->right = build(rpb, rpe, rib, rie);

    return root;
  }

  int find_in(int ib, int ie, int target)
  {
    int ret = ib;
    for (; ret != ie; ++ret)
    {
      if (inorder_[ret] == target)
        break;
    }
    return ret;
  }

private:
  vector<int> preorder_;
  vector<int> inorder_;
};

int main() {
    vector<int> pre = {1,2,4,7,3,5,6,8};
    vector<int> in = {4,7,2,1,5,3,8,6};
    TreeNode* root = Solution().reConstructBinaryTree(pre, in);
    PreorderTranverse(root);
    cout << "\n";
    InorderTranverse(root);
    return 0;
}
