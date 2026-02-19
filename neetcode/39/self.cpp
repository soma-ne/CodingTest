#include <vector>

class Node {
public:
    int val;
    Node* next;
    Node* random;
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
		Node* cur = head;
		Node* new_head = nullptr;
		std::vector<Node*> vec;
		std::vector<Node*> copy_vec;

		int cnt = 0;
		while (cur != nullptr) {
			vec.push_back(cur);

			Node* copy = new Node(cur->val);
			copy_vec.push_back(copy);
			cur->val = cnt;
			cur = cur->next;

			if (cnt == 0)
				new_head = copy;

			cnt++;
		}

		for (int i=0;i<cnt;i++) {
			if (i < cnt - 1)
				copy_vec[i]->next = copy_vec[i+1];
<<<<<<< Updated upstream
			Node* random = vec[i]->random;
			copy_vec[i]->random =
				(vec[i]->random != nullptr) ? copy_vec[vec[i]->random->val] : nullptr;
=======
			copy_vec[i]->random =
				copy_vec[vec[i]->random->val];
>>>>>>> Stashed changes
		}

		return new_head;
    }
};

int main()
{
	Node* n1 = new Node(3);
	Node* n2 = new Node(7);
	Node* n3 = new Node(4);
	Node* n4 = new Node(5);
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n1->random = nullptr;
	n2->random = n4;
	n3->random = n1;
	n4->random = n2;

	Solution sol;
	sol.copyRandomList(n1);
}
