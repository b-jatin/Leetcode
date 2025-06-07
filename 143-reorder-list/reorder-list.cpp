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
        ListNode* dummy= new ListNode();
        ListNode* ans=head, *slow=head, *fast=head;

        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* prev=NULL, *forward;
        if(fast->next)
        fast=fast->next;
        
        while(slow!=NULL){
            forward=slow->next;
            slow->next=prev;
            prev=slow;
            slow=forward;
        }
        slow=prev;
        while(head && slow){
            forward=head->next;
            head->next=slow;
            prev=slow->next;
            slow->next=forward;
            head=forward;
            slow=prev;

        }

        if (head && head->next) head->next->next = NULL;
    


    }
};