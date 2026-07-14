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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size=0;
        ListNode* sizeChecker = head;
        while(sizeChecker!=nullptr){
            size++;
            sizeChecker = sizeChecker->next;
        }
        int required = size-n;
        if(required==0) return head->next;
        
        ListNode* prev = head;
        ListNode* curr = head;
        for(int i=0 ; i < required + 1 ; i++){
            if( i == required){
                prev->next = curr->next;
                break;
            }
            prev = curr;
            curr = curr->next;
        }
        return head;
    }
};
