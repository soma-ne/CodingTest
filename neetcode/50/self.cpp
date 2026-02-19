#include <queue>

class Solution
{
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot)
	{
		std::queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
			auto node = q.front();
			q.pop();

			if (isSameTree(node, subRoot))
				return true;

			if (node->left != nullptr)
				q.push(node->left);

			if (node->right != nullptr)
				q.push(node->right);
		}
		return false;
    }

    bool isSameTree(TreeNode* p, TreeNode* q)
	{
		if (p == nullptr && q != nullptr)
			return false;
		if (p != nullptr && q == nullptr)
			return false;
		if (p == nullptr && q == nullptr)
			return true;
		if (p->val != q->val)
			return false;
		if (!isSameTree(p->left, q->left))
			return false;
		if (!isSameTree(p->right, q->right))
			return false;
		return true;
    }
};

