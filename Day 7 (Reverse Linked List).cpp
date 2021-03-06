/*
Question Link -> https://leetcode.com/problems/reverse-linked-list/

Given the head of a singly linked list, reverse the list, and return the reversed list. 

Example 1:
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]

Example 2:
Input: head = [1,2]
Output: [2,1]

Example 3:
Input: head = []
Output: []

Constraints:
  The number of nodes in the list is the range [0, 5000].
  -5000 <= Node.val <= 5000 

Follow up: A linked list can be reversed either iteratively or recursively. Could you implement both?
*/

//C++ Code:

//Iterative Approach:

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *curr=head, *prev=NULL, *temp=NULL;
        while(curr)
        {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
};


//Recursive Approach:

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode* next_node = head->next;
        head->next = NULL;
        ListNode* root = reverseList(next_node);
        next_node->next = head;
        return root;
    }
};
