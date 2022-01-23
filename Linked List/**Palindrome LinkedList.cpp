// 206. Reverse Linked List
// Easy


// Given the head of a singly linked list, reverse the list, and return the reversed list.
class Solution {
public:
       ListNode* reverse(ListNode* head) {
        ListNode* c=head;
        ListNode* p=NULL;
         ListNode* n;
        while(c!= NULL){
           n= c->next;
            c->next=p;
            p=c;
            c=n;
        }
        head=p;
        return head;
    }
    
    bool isPalindrome(ListNode* head) {
        ListNode* fast = head, *slow = head;
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    if (fast != NULL) { 
        slow = slow->next;
    }
    slow = reverse(slow);
    fast = head;
    
    while (slow != NULL) {
        if (fast->val != slow->val) {
            return false;
        }
        fast = fast->next;
        slow = slow->next;
    }
    return true;
    }
};
//RECURSIVE APPROCT WITH EXTRA SPACE
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* c=head;
        ListNode* p=NULL;
         ListNode* n;
        while(c!= NULL){
           n= c->next;
            c->next=p;
            p=c;
            c=n;
        }
        head=p;
        return head;
    }
};
