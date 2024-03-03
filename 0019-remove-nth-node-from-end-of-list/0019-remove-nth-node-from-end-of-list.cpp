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
    
    int size(ListNode* head){
        int size = 0;
        
        while(head){
            size++;
            head = head->next;
        }
        
        return size;
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       
        int s = size(head);
        
        int t = s - n;
        
        if(t == 0){
            head = head->next;
            return head;
        }
        
        ListNode* start = head;
        
        int pos = 1;
        
        while(start){

            if(pos == t){
                start->next = start->next->next;
                break;
            }
            
            pos+=1;
            start = start->next;
        }
        
        return head;
    }
};