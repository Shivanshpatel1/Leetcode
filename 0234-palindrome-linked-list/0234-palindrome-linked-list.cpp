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


    ListNode* reversell(ListNode* head){
        ListNode* prev=NULL;
        ListNode* curr=head;
        while(curr!=NULL){
            ListNode* next = curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        
        return prev;
    }

    bool isPalindrome(ListNode* &head) {
        if(head==NULL){
            return true;
        }
        if(head->next==NULL){
            return true;
        }
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL){
            fast=fast->next;
            if(fast!=NULL){
                fast=fast->next;
                slow=slow->next;
            }
        }
        
        ListNode* forward = slow;
        ListNode* part = reversell(forward);
        while(part!=NULL){
            if(head->val!=part->val){
                return false;
            }else{
                head=head->next;
                part=part->next;
            }
        }
        return true;
    }
};