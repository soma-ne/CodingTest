#include <queue>

class Solution
{
	int count = 0;
public:
	int goodNodes(TreeNode* root)
	{
		std::queue<std::pair<TreeNode*,int>> q;
		q.push({root, -101});
		while (!q.empty()) {
			auto [node, max] = q.front();
			q.pop();
			if (node->val >= max)
				count++;
			max = std::max(max, node->val);
			if (node->left != nullptr)
				q.push({node->left, max});
			if (node->right != nullptr)
				q.push({node->right, max});
		}

		return count;
	}
};
