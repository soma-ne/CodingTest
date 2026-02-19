#include <utility>

class Solution
{
public:
	TreeNode* invertTree(TreeNode* root)
	{
		if (root == nullptr)
			return nullptr;
		if (root->left != nullptr)
			invertTree(root->left);
		if (root->right != nullptr)
			invertTree(root->right);
		std::swap(root->left, root->right);
		return root;
	}
};
