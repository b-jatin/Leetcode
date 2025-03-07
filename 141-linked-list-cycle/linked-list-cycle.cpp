/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
       ListNode * fast= head, *slow=head;
        if(head==NULL)
        return false;
       while(fast!=NULL && fast->next!= NULL){
        slow= slow->next;
        fast=fast->next->next;
        if(fast==slow)
        return true;
       }
       return false;

       
       /* unordered_set <ListNode *> temp;
         while(head!=NULL){
            if(temp.find(head)!=temp.end())
            return true;
            
            temp.insert(head);
            head=head->next;
        }
        return false; */
    }
};