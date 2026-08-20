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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head) return nullptr;
        ListNode* temp=head;
        int i=0;
        while(i<k){
            if(!temp) return head;
            temp=temp->next;
            i++;
        }
        ListNode* prev=nullptr;
        ListNode* curr=head;
        for(int i=0;i<k;i++){
            ListNode* forw=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forw;
        }
        head->next=reverseKGroup(curr,k);
        return prev;
    }
};