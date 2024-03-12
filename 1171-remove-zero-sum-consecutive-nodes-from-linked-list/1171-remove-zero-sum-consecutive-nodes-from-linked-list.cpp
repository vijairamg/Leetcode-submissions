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
    ListNode* removeZeroSumSublists(ListNode* head) {
        
        ListNode* cur = head;
        ListNode* prev = nullptr;
        
        bool changed = false;
        
        while(cur){
                    
            int sum = cur->val;
            bool found = false;
            
            if(cur->val == 0){
                if(!prev){
                    head = cur->next;
                }else{
                    prev->next = cur->next;
                }
                cur = cur->next;
                continue;
            }
            
            ListNode* start = cur->next;
            
            while(start){
                sum += start->val;
                
                if(sum == 0){
                    // cout<<"found "<<cur->val<<" "<<start->val<<endl;
                    break;
                }
                
                start = start->next;
            }
            
            if(start){
                changed = true;
                if(!prev){
                    head = start ? start->next : nullptr;
                    cur = start ? start->next : nullptr;
                }else{
                    prev->next = start ? start->next : nullptr;
                    cur = start ? start->next : nullptr;
                }
            }else{
                prev = cur;
                cur = cur->next;  
            }
        }
        
        return changed ? removeZeroSumSublists(head) : head;
    }
};