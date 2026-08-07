/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
   public:
    ListNode* mergeTwoLists(ListNode* prev, ListNode* next) {
        ListNode* mover1 = prev;
        ListNode* mover2 = next;

        ListNode* ans = new ListNode(0);
        ListNode* ansMover = ans;
        while (mover1 != nullptr && mover2 != nullptr) {
            if (mover1->val < mover2->val) {
                
                ansMover->next = mover1;
                ansMover = ansMover->next;
                mover1 = mover1->next;
            } else {
                
                ansMover->next = mover2;
                ansMover = ansMover->next;
                mover2 = mover2->next;
            }
        }
        if (mover1 == nullptr) {
            while (mover2 != nullptr) {
                
                ansMover->next = mover2;
                ansMover = ansMover->next;
                mover2 = mover2->next;
            }
        } else {
            while (mover1 != nullptr) {
                
                ansMover->next = mover1;
                ansMover = ansMover->next;
                mover1 = mover1->next;
            }
        }
        return ans->next;
    }

    ListNode* mergeSort(vector<ListNode*>& lists, int low, int high) {
        if (low >= high) return lists[low];
        int mid = low + (high - low) / 2;
        ListNode* prev = mergeSort(lists, low, mid);
        ListNode* next = mergeSort(lists, mid + 1, high);
        return mergeTwoLists(prev, next);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        int low = 0;
        int high = lists.size() - 1;
        int mid = low + (high - low) / 2;
        return mergeSort(lists, low, high);
    }
};
