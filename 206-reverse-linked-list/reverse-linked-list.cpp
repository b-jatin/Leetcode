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
        stack<int> st;
        ListNode* temp, *forward, *previous=NULL;
        temp=head;
        while(temp != NULL){
            forward=temp->next;
            temp->next=previous;
            previous=temp;
            temp=forward;
        }
        return previous;
        
    }
};