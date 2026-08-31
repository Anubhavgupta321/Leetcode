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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(!head || !head->next || !head->next->next) return {-1,-1};
        bool first=true;
        ListNode* temp=head->next;
        int fidx=-1,pidx=-1,lidx=-1;
        int mindis=INT_MAX;
        int i=0;
        ListNode* prev=head;
        while(temp->next){
            if((temp->val>prev->val && temp->val>temp->next->val) || (temp->val<prev->val && temp->val<temp->next->val)){
                if(first){
                    fidx=i;
                    pidx=i;
                    first=false;
                    i++;
                    prev=temp;
                    temp=temp->next;
                    continue;
                }
                lidx=i;
                mindis=min(mindis,lidx-pidx);
                pidx=i;
                i++;
                prev=temp;
                temp=temp->next;
            }
            else{
                prev=temp;
                temp=temp->next;
                i++;
            }
        }
        if(mindis==INT_MAX) return {-1,-1};
        return {mindis,lidx-fidx};
    }
};