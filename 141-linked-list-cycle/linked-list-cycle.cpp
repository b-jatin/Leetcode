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
        unordered_set <ListNode *> temp;
        while(head!=NULL){
            if(temp.find(head)!=temp.end())
            return true;
            
            temp.insert(head);
            head=head->next;
        }
        return false;
    }
};