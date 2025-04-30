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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* res = new ListNode(0, head);
        ListNode* iter = res;
        for(int i = 0;i<n;i++){
            head = head->next;
        }
        while(head != nullptr){
            head=head->next;
            iter = iter->next;
        }
        iter->next=iter->next->next;
        return res->next;        
    }
};