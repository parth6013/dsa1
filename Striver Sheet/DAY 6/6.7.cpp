// rotate a linked list

// bute force 
#include<bits/stdc++.h>
using namespace std;


//   Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head==NULL || head->next==NULL){
            return head;
        }
        
        ListNode*temp4=head;
        int n=0;
        while(temp4){
            n++;
            temp4=temp4->next;
        }
        k=k%n;
        
        while(k>0){
            ListNode* temp= head;
        ListNode* pre= new ListNode();
        pre->next=head;
            while(temp->next!=NULL){
                temp=temp->next;
                pre=pre->next;
            }
            pre->next=NULL;
            temp->next=head;
            head=temp;
            k--;
            
        }
        return head;
        
    }
};

// Optimum
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
    ListNode* rotateRight(ListNode* head, int k) {
             if (head == NULL) // If the list is empty
            return head;
        
        ListNode *itr = head, *fwd, *new_head;
        int len = 0, kFront, ctr=0;
        while (itr != NULL) { // To get the length of the list
            itr = itr->next;
            len++;
        }
        
        k = k%len; // To avoid unnecessary rotations
        
        if (k == 0) // If no rotation is needed
            return head;
        
        kFront = len - (k+1);
        itr = head;
        while (ctr < kFront) { // Iterate to element before the K th rotation 
            itr = itr->next;
            ctr++;
        }
        
        new_head = itr->next; 
        itr->next = NULL; // Setting the next of node before k th rotation to NULL
        fwd = new_head;
        
        while (fwd->next) {
            fwd = fwd->next;
        }
        fwd->next = head;
        
        return new_head;        
   
    }
};