class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
            return nullptr;

        while (lists.size() > 1) {
            vector<ListNode*> merged;

            for (int i = 0; i < lists.size(); i += 2) {
                ListNode* l1 = lists[i];
                ListNode* l2 =
                    (i + 1 < lists.size()) ? lists[i + 1] : nullptr;

                merged.push_back(mergeLists(l1, l2));
            }

            lists = move(merged);
        }

        return lists[0];
    }

    ListNode* mergeLists(ListNode* l1, ListNode* l2) {
        ListNode dummy;
        ListNode* curr = &dummy;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }

            curr = curr->next;
        }

        curr->next = l1 ? l1 : l2;

        return dummy.next;
    }
};