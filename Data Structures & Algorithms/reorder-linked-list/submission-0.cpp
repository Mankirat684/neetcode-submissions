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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=nullptr&&fast->next!=nullptr){
            slow=slow->next;
            fast = fast->next->next;
        }
    // now slow is at mid point when fast is at the end.

        

        
        // second half reversing:

        ListNode* prev = nullptr;
        ListNode* curr = slow->next;
        slow->next = nullptr;
        ListNode* next = curr->next;

        while(curr!=nullptr){
            next = curr->next;
            curr->next = prev;
            prev=curr;
            curr=next;
        }

        // merging two halfs:
        ListNode* head2 = prev;
        ListNode* head1 = head;

        ListNode* next1 = head1;
        ListNode* next2 = head2;
        while(head2!=nullptr){
            next1=next1->next;
            next2=next2->next;

            head1->next =head2;
            head2->next= next1;

            head1=next1;
            head2=next2;
        }
        
    }
};
