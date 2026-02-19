class Solution
{
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* cur = new ListNode;
		ListNode* head = cur;
		int carry = 0;
		while (l1 != nullptr || l2 != nullptr) {
			int val1 = val(l1);
			int val2 = val(l2);
			int sum = val1 + val2 + carry;
			int new_val = sum % 10;
			carry = sum / 10;

			cur->next = new ListNode(new_val);

			cur = cur->next;
<<<<<<< Updated upstream
			l1 = next(l1);
			l2 = next(l2);
=======
			l1 = l1->next;
			l2 = l2->next;
>>>>>>> Stashed changes
		}

		if (carry != 0) {
			cur->next = new ListNode(carry);
		}

		cur = head->next;
		delete head;

		return cur;
	}

	int val(ListNode* l) {
		if (l == nullptr)
			return 0;
		return l->val;
	}
<<<<<<< Updated upstream

	ListNode* next(ListNode* l)
	{
		if (l == nullptr)
			return nullptr;
		return l->next;
	}
};


=======
};
>>>>>>> Stashed changes
