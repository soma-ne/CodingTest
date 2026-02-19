#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists)
	{
		int n = lists.size();
		ListNode* head = new ListNode;
		ListNode* cur = head;

		while (!empty(lists)) {
			int min = 1001;
			int idx;
			for (int i=0;i<n;i++) {
				auto l = lists[i];
				if (l == nullptr)
					continue;
				if (l->val < min) {
					idx = i;
					min = l->val;
				}
			}

			cur->next = new ListNode(lists[idx]->val);
			lists[idx] = lists[idx]->next;
			cur = cur->next;
		}

		cur = nullptr;
		if (head->next != nullptr)
			cur = head->next;
		delete head;
		return cur;
    }

	bool empty(std::vector<ListNode*>& lists)
	{
		for (auto l : lists) {
			if (l != nullptr)
				return false;
		}
		return true;
	}
};

