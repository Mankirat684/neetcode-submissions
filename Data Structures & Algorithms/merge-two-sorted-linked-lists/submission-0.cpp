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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* mover1 = list1;
        ListNode* mover2 = list2;
        
        ListNode* ans = new ListNode(0);
        ListNode* ansMover = ans;
        while(mover1!=nullptr&&mover2!=nullptr){
            if(mover1->val<mover2->val){
                ListNode* temp = new ListNode(mover1->val);
                ansMover->next = temp;
                ansMover = temp;
                mover1 = mover1->next;
            }else{
                ListNode* temp = new ListNode(mover2->val);
                ansMover->next = temp;
                ansMover = temp;
                mover2 = mover2->next;
            }
        }
        if(mover1==nullptr){
            while(mover2!=nullptr){
                ListNode* temp = new ListNode(mover2->val);
                ansMover->next = temp;
                ansMover = temp;
                mover2 = mover2->next;
            }
        }else{
            while(mover1!=nullptr){
            ListNode* temp = new ListNode(mover1->val);
            ansMover->next = temp;
            ansMover = temp;
            mover1 = mover1->next;
            }
        }
        return ans->next;
    }
};
