#include <queue>

class Solution
{
public:
	std::vector<std::vector<int>> levelOrder(TreeNode* root)
	{
		if (root == nullptr)
			return std::vector<std::vector<int>>();

		std::queue<TreeNode*> a;
		std::queue<TreeNode*> b;
		a.push(root);
		std::vector<std::vector<int>> ret;
		while (!a.empty() || !b.empty()) {
			std::vector<int> vec;
			while (!a.empty()) {
				auto node = a.front();
				a.pop();
				vec.push_back(node->val);
				if (node->left != nullptr)
					b.push(node->left);
				if (node->right != nullptr)
					b.push(node->right);
			}
			ret.push_back(vec);
			if (b.empty())
				break;
			vec.clear();
			while (!b.empty()) {
				auto node = b.front();
				b.pop();
				vec.push_back(node->val);
				if (node->left != nullptr)
					a.push(node->left);
				if (node->right != nullptr)
					a.push(node->right);
			}
			ret.push_back(vec);
		}
		return ret;
	}
};
