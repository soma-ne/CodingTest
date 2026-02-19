class Solution
{
public:
	bool hasCycle(ListNode* head)
	{
		while (head != nullptr) {
			if (head->val == -1)
				return true;
			head->val = -1;
			head = head->next;
		}
		return false;
	}
};
