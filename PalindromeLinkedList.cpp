class Solution {
public:
	bool isPalindrome(ListNode* head) {
		if (head == 0)
			return true;
		ListNode *prev = 0;
		ListNode *tort = 0;
		ListNode *hare = 0;
		ListNode *tnext = 0;
		tort = head;
		tnext = head->next;
		hare = (tnext != 0) ? tnext->next : 0;
		if (hare == 0 && tnext == 0)
			return true;
		if (hare == 0)
			return (tort->val == tnext->val);

		while (hare != 0 && hare->next != 0) {
			tort->next = prev;
			prev = tort;
			tort = tnext;
			tnext = tnext->next;
			hare = hare->next;
			if (hare != 0)
				hare = hare->next;
		}
		tort->next = prev;
		ListNode *sec = (hare != 0) ? tnext->next : tnext;
		bool result = true;
		while (sec != 0) {
			result &= (tort->val == sec->val);
			tort = tort->next;
			sec = sec->next;
		}
		return result;
	}
};
