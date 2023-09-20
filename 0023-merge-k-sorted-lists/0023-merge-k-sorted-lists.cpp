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

class cmp{
    public:
    bool operator()(ListNode* &a, ListNode* &b){
        return a->val>b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> minHeap;
        for(auto x:lists){
            if(x!=NULL){
                minHeap.push(x);
            }
        }

        ListNode* head=NULL;
        ListNode* tail = NULL;

        while(!minHeap.empty()){
            auto top = minHeap.top();
            minHeap.pop();

            if(head==NULL){
                head=top;
                tail=top;
                if(top->next){
                    minHeap.push(tail->next);
                }
            }else{
                tail->next=top;
                tail=top;
                if(top->next){
                    minHeap.push(tail->next);
                }
            }
        }
        return head;
    }
};