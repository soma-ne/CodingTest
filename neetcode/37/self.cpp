#include <stack>

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
	void reorderList(ListNode* head)
	{
		ListNode* cur = head;
		std::stack<ListNode*> st;
		while (cur != nullptr) {
			st.push(cur);
			cur = cur->next;
		}

		int cnt = 0;
		while (1) {
			ListNode* tail = st.top();
			if (cnt % 2 == 0) {
				if (head == tail) {
					head->next= nullptr;
					break;
				}
				ListNode* next = head->next;
				head->next = tail;
				head = next;
			} else {
				if (head == tail) {
					tail->next= nullptr;
					break;
				}
				st.pop();
				tail->next = head;
			}
			cnt++;
		}
	}
};

int main()
{
	ListNode* head = new ListNode(2);
	ListNode* cur = head;
	cur->next = new ListNode(4);
	cur = cur->next;
	cur->next = new ListNode(6);
	cur = cur->next;
	cur->next = new ListNode(8);
	Solution sol;
	sol.reorderList(head);
}
