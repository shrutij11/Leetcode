// In a linked list of size n, where n is even, the ith node (0-indexed) of the linked list is known as the twin of the (n-1-i)th node, if 0 <= i <= (n / 2) - 1.

// For example, if n = 4, then node 0 is the twin of node 3, and node 1 is the twin of node 2. These are the only nodes with twins for n = 4.
// The twin sum is defined as the sum of a node and its twin.

// Given the head of a linked list with even length, return the maximum twin sum of the linked list.

 

// Example 1:


// Input: head = [5,4,2,1]
// Output: 6
// Explanation:
// Nodes 0 and 1 are the twins of nodes 3 and 2, respectively. All have twin sum = 6.
// There are no other nodes with twins in the linked list.
// Thus, the maximum twin sum of the linked list is 6. 




class Solution {
public:
    int pairSum(ListNode* head) {
       ListNode* slow = head;
	ListNode* fast = head;
	int maxVal = 0;

	
	while(fast && fast -> next)
	{
		fast = fast -> next -> next;
		slow = slow -> next;
	}

	ListNode *nextNode, *prev = NULL;
	while (slow) {
		nextNode = slow->next;
		slow->next = prev;
		prev = slow;
		slow = nextNode;
	}

	while(prev)
	{
		maxVal = max(maxVal, head -> val + prev -> val);
		prev = prev -> next;
		head = head -> next;
	}

	return maxVal;
        
    }
};
