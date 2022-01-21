// 203. Remove Linked List Elements
// Easy
// Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.

 

// Example 1:


// Input: head = [1,2,6,3,4,5,6], val = 6
// Output: [1,2,3,4,5]


//using single pointer
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
         if(head==NULL) return head;
          while(head!=nullptr && head->val==val){
            head = head->next;
        }
        
         if(head==nullptr) return head;
        while(head!=nullptr && head->val==val){
            head = head->next;
        }
        ListNode* curr = head;
        while(curr!=nullptr  && curr->next!=nullptr){
            if(curr->next->val==val){
                curr->next = curr->next->next;
				
            }
            else
                curr = curr->next;
        }
        return head;
    }
};

//using two pointers

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
         if(head==NULL) return head;
          while(head!=nullptr && head->val==val){
            head = head->next;
        }
        
         ListNode* prev =NULL;
         ListNode* cur =head;
        while(cur != NULL){
        if(cur->val == val){
            prev->next = cur->next;
             cur = cur->next;
        }
        else{
            prev=cur;
            cur=cur->next;
        }
            
        }     
        return  head;
    }
};
