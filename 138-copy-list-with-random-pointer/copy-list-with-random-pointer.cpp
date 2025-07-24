/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
       Node * dummy=new Node(-1);
       dummy->next= head;

       if(head==NULL)
       return head;
        
        while(head!=NULL){
            Node * temp= new Node(head->val);
            temp->next=head->next;
        
            head->next=temp;
            head=temp->next;
        }
        Node * temp=dummy->next;
        while(temp!=NULL){
            if(temp->random){
            temp->next->random=temp->random->next;
            }
            else{
                temp->next->random=NULL;
            }
            temp=temp->next->next;
        }
        
        
        Node * ans=new Node(-1);
        Node * copyList=ans;
        head=dummy->next;
        while(head!=NULL){
            copyList->next=head->next;
            copyList=copyList->next;
            head->next=copyList->next;
            head=head->next;
        }
        return ans->next;
        
    }
};