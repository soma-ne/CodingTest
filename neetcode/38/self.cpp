#include <iostream>

class Solution
{
public:
	ListNode* removeNthFromEnd(ListNode* head, int n)
	{
		int size = countList(head);
		int remove_idx = size - n;

		if (remove_idx == 0)
			return head->next;

		ListNode* cur = head;
		for (int i=0;i<remove_idx-1;i++) {
			cur = cur->next;
		}

		cur->next = cur->next->next;

		return head;
	}

	int countList(ListNode* head)
	{
		int size = 0;
		while (head != nullptr) {
			size++;
			head = head->next;
		}

		return size;
	}
};
