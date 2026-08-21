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
    typedef pair<int,ListNode*> pi;
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        for(auto first:lists){
            if(first) pq.push({first->val,first});
        }
        ListNode* dummy=new ListNode(0);
        ListNode* temp=dummy;
        while(!pq.empty()){
            auto [val,node]=pq.top();
            pq.pop();
            temp->next=node;
            temp=temp->next;
            if(node->next) pq.push({node->next->val,node->next});
        }
        return dummy->next;
    }
};