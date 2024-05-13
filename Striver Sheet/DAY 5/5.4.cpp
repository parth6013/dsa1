// Remove Nth Node From End of List

// normal brute logic
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode*temp=head;
        ListNode*temp2=head;
        int s=0;
        while(temp!=NULL){
            s++;
            temp=temp->next;
        }
        
        int z=s-n+1;
        
        if(z==1){
            head=head->next;
            return head;
        }
        int k=0;
        while(k!=z-2){
            k++;
            temp2=temp2->next;
        }
        temp2->next=temp2->next->next;
        
        return head;
        
    }
};

// using fast and slow pointer and dummy pointer
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
        
//         assigning a dummy pointer 
        
        ListNode*start = new ListNode();
        start->next=head;
        ListNode*fast=start;
        ListNode*slow=start;
        
        for(int i=1;i<=n;++i){
            fast=fast->next;
        }
        
        while(fast->next!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
        
        slow->next=slow->next->next;
        
        return start->next;
    }
};