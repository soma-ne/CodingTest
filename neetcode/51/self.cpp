#include <tuple>
#include <algorithm>


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};



class Solution
{
	int lca_height = 101;
	TreeNode* lca;
	TreeNode* p;
	TreeNode* q;
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* _p, TreeNode* _q)
	{
		p = _p;
		q = _q;
		dfs(root);
		return lca;
	}

	std::tuple<int, bool, bool> dfs(TreeNode* node)
	{
		int l = 0, r = 0;
		bool pflag = false, qflag = false;
		if (node->left != nullptr) {
			auto [lt, pt, qt] = dfs(node->left);
			l = lt + 1;
			pflag += pt;
			qflag += qt;
		}

		if (node->right != nullptr) {
			auto [rt, pt, qt] = dfs(node->right);
			r = rt + 1;
			pflag += pt;
			qflag += qt;
		}

		if (node == p)
			pflag = true;
		if (node == q)
			qflag = true;

		int height = std::max(l, r);

		if (pflag && qflag && height < lca_height) {
			lca_height = height;
			lca = node;
		}

		return {height, pflag, qflag};
	}
};
