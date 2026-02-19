class Solution
{
public:
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
	{
		ListNode* head = new ListNode;
		ListNode* cur = head;
		while (list1 != nullptr || list2 != nullptr) {
			bool selected = false;
			if (list1 != nullptr &&
					(list2 == nullptr || list1->val < list2->val))
				selected = true;

			if (selected) {
				cur->next = list1;
				list1 = list1->next;
				cur = cur->next;
				cur->next = nullptr;
			} else {
				cur->next = list2;
				list2 = list2->next;
				cur = cur->next;
				cur->next = nullptr;
			}
		}

		return head->next;
	}
};
