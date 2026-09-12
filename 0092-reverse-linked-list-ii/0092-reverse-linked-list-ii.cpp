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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head) return head;
        ListNode* dummy=new ListNode(-1);
        dummy->next=head;
        ListNode* temp=dummy;
        int i=1;
        while(i<left){
            temp=temp->next;
            i++;
        }
        ListNode* forw=nullptr;
        ListNode* curr=temp->next;
        while(i<right && curr){
            forw=curr->next;
            curr->next=forw->next;
            forw->next=temp->next;
            temp->next=forw;
            i++;
        }
        return dummy->next;
    }
};