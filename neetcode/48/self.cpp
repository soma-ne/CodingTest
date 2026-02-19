#include <cmath>

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
	bool balanced = true;
public:
    bool isBalanced(TreeNode* root)
	{
		if (root == nullptr)
			return true;
		height(root);
		return balanced;
    }

	int height(TreeNode* root)
	{
		int l = 0, r = 0;
		if (root->left != nullptr)
			l = height(root->left) + 1;
		if (root->right != nullptr)
			r = height(root->right) + 1;

		if (std::abs(l - r) > 1)
			balanced = false;

		return std::max(l, r);
	}
};

