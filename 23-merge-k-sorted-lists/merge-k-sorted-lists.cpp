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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy= new ListNode(-1);
        ListNode* temp=dummy;

        priority_queue<pair<int,ListNode *>,vector<pair<int,ListNode*>>, greater<pair<int,ListNode*>>> pq;  

        for(auto i: lists){
            if(i!=NULL)
            pq.push({i->val,i});
            }

            while(!pq.empty()){
                ListNode* min;
                min=pq.top().second;
                pq.pop();
                if(min->next!=NULL){
                    pq.push({min->next->val,min->next});
                }

                temp->next=min;
                temp=temp->next;
            }

        return dummy->next;

    }
};