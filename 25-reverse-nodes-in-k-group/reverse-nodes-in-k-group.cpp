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
    ListNode* getkthNode(ListNode* head, int k) {
        k--;
        while (head != NULL && k--) {
            head = head->next;
        }
        return head;
    }

    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        while (curr != NULL) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k <= 1) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prevLast = dummy;
        ListNode* temp = head;

        while (temp != NULL) {
            ListNode* kth = getkthNode(temp, k);
            if (kth == NULL) {
                prevLast->next = temp;
                break;
            }

            ListNode* nextGroup = kth->next;
            kth->next = NULL;

            ListNode* newHead = reverse(temp); 
            prevLast->next = newHead;
            prevLast = temp;
            temp = nextGroup;
        }

        return dummy->next;
    }
};
