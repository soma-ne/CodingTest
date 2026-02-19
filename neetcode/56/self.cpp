class Solution
{
	int k;
	int kth;
public:
	int kthSmallest(TreeNode* root, int k)
	{
		this->k = k;
		dfs(root);
		return kth;
	}

	void dfs(TreeNode* node)
	{
		if (node->left != nullptr)
			dfs(node->left);

		k--;
		if (k == 0)
			kth = node->val;

		if (node->right != nullptr)
			dfs(node->right);
	}
};
