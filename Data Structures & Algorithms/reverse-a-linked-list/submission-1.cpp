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
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr||head->next==nullptr) return head;

        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* next = curr->next;
        prev->next=nullptr;
        while(curr!=nullptr){
            if(next==nullptr){
                curr->next = prev;
                prev=curr;
                return prev;
            }
            curr->next = prev;
            prev= curr;
            curr = next;
            if(curr->next == nullptr){
                curr->next=prev;
                prev = curr;
                return prev;
            }
            next = curr->next;
        }
        return prev;
    }
};
