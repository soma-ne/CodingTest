#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution
{
public:
    ListNode* reverseKGroup(ListNode* head, int k)
	{
		ListNode* ret = new ListNode;
		auto cur = ret;

		while (head != nullptr) {
			if (!longer(head, k)) {
				concat(cur, head, k);
			} else {
				ListNode* rev = reverse(head, k);
				concat(cur, rev, k);
				free(rev);
			}

			head = proceed(head, k);
			cur = last(cur);
		}

		if (ret->next == nullptr)
			return nullptr;
		cur = ret->next;
		return cur;
    }

	bool longer(ListNode* head, int k)
	{
		if (head == nullptr)
			return false;

		int n = 1;
		for (int i=0;i<k-1;i++) {
			if (head->next == nullptr)
				break;
			head = head->next;
			if (head != nullptr)
				n++;
		}

		return n == k;
	}

	void concat(ListNode* last, ListNode* head, int k)
	{
		for (int i=0;i<k;i++) {
			if (head == nullptr)
				break;
			ListNode* node = new ListNode(head->val);
			last->next = node;
			last = last->next;
			head = head->next;
		}
	}

	ListNode* reverse(ListNode* head, int k)
	{
		ListNode* rev = new ListNode(head->val);
		ListNode* ret = rev;
		head = head->next;
		for (int i=1;i<k;i++) {
			ListNode* node = new ListNode(head->val);
			node->next = rev;
			rev = node;
			head = head->next;
		}
		return rev;
	}

	void free(ListNode* head)
	{
		ListNode* tmp;
		while (head != nullptr) {
			tmp = head;
			head = head->next;
			delete tmp;
		}
	}

	ListNode* proceed(ListNode* head, int k)
	{
		for (int i=0;i<k;i++) {
			if (head == nullptr)
				return nullptr;
			head = head->next;
		}
		return head;
	}

	ListNode* last(ListNode* head)
	{
		while (head->next != nullptr) {
			head = head->next;
		}
		return head;
	}

	void debug(ListNode* l)
	{
		while (l != nullptr) {
			std::cout << l->val << " => ";
			l = l->next;
		}
		std::cout << std::endl;
	}
};

int main()
{
	ListNode n1(1);
	ListNode n2(2);
	ListNode n3(3);
	ListNode n4(4);
	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	Solution sol;
	sol.reverseKGroup(&n1, 3);
}
