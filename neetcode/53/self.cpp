#include <queue>
#include <vector>

class Solution
{
public:
	std::vector<int> rightSideView(TreeNode* root)
	{
		std::vector<int> ret;
		if (root == nullptr)
			return ret;
		std::queue<TreeNode*> a;
		std::queue<TreeNode*> b;
		a.push(root);
		while (!a.empty() || !b.empty()) {
			int right;
			while (!a.empty()) {
				auto node = a.front();
				a.pop();
				if (node->left != nullptr)
					b.push(node->left);
				if (node->right != nullptr)
					b.push(node->right);
				right = node->val;
			}
			ret.push_back(right);

			if (b.empty())
				break;

			while (!b.empty()) {
				auto node = b.front();
				b.pop();
				if (node->left != nullptr)
					a.push(node->left);
				if (node->right != nullptr)
					a.push(node->right);
				right = node->val;
			}
			ret.push_back(right);
		}

		return ret;
	}
};
