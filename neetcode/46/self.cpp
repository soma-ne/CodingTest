#include <algorithm>

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
    int maxDepth(TreeNode* root)
	{
		if (root == nullptr)
			return 0;

		int l = 1, r = 1;
		if (root->left != nullptr)
			l = maxDepth(root->left) + 1;
		if (root->right != nullptr)
			r = maxDepth(root->right) + 1;
		return std::max(l, r);
    }
};

