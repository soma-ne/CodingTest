class Solution
{
	bool validity = true;
public:
	bool isValidBST(TreeNode* root)
	{
		dfs(root);
		return validity;
	}

	std::pair<int, int> dfs(TreeNode* node)
	{
		int val = node->val;
		int lmin = val, lmax = val;
		int rmin = val, rmax = val;

		if (node->left != nullptr) {
			std::tie(lmin, lmax) = dfs(node->left);
			if (lmax >= val)
				validity = false;
		}
		if (node->right != nullptr) {
			std::tie(rmin, rmax) = dfs(node->right);
			if (val >= rmin)
				validity = false;
		}

		return {lmin, rmax};
	}
};
