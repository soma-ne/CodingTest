class Solution
{
public:
	ListNode* reverseList(ListNode* head)
	{
		if (head == nullptr)
			return nullptr;
		ListNode *rhead = new ListNode;
		reverse(rhead, head);
		return rhead->next;
	}

	ListNode* reverse(ListNode* rhead, ListNode* head)
	{
		if (head->next == nullptr) {
			rhead->next = head;
			return rhead->next;
		}
		rhead = reverse(rhead, head->next);
		head->next = nullptr;
		rhead->next = head;
		return rhead->next;
	}
};
