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
        
        ListNode* dummy=new ListNode();
        ListNode* temp=dummy;
        
        while(list1 && list2){
            if(list1->val<list2->val){
                temp->next=list1;
                list1=list1->next;
            }
            else{
                temp->next=list2;
                list2=list2->next;
            }
            temp=temp->next;
        }
        temp->next=(list1)?list1:list2;
        return dummy->next;
        /*int max1=INT_MIN, max2=INT_MIN;
        if(list1==NULL)
        return list2;
        if(list2==NULL)
        return list1;
        while(list1!=NULL && list2!=NULL){
            if(list1->val>=max1){
                max1=list1->val;
            }
            if(list2->val>=max2){
                max2=list2->val;
            }
            if((list1->val<=list2->val) &&(max1<=max2)){
                ans=list1;
                ans->next=list2;
                
            }
            else{//((list2->val<=list1->val) &&(max2<=max1))
                ans=list2;
                ans->next=list1;
            }
            list1=list1->next;
            list2=list2->next;
        }
        ans->next=NULL;
        return ans;*/
    }
};