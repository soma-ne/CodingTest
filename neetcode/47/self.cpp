#include <algorithm>

class Solution
{
	int d = 0;
public:
	int diameterOfBinaryTree(TreeNode* root)
	{
		if (root == nullptr)
			return 0;
		dfs(root);
		return d;
	}

	int dfs(TreeNode* root)
	{
		int l = 0, r = 0;
		if (root->left != nullptr)
			l = dfs(root->left) + 1;
		if (root->right != nullptr)
			r = dfs(root->right) + 1;

		d = std::max(d, l + r);
		std::cout << root->val << ":" << l << " " << r << std::endl;

		return std::max(l, r);
	}
};
