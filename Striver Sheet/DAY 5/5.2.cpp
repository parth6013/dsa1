// find the middle element of linked list


// find the lenth of linked list using 1 while loop then return the n/2 +1 element

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
    ListNode* middleNode(ListNode* head) {
        int n=0;
        ListNode*temp=head;
        while(head!=NULL){
            n++;
            // cout<<head->val<<"#";
            head=head->next;
        }
        cout<<n;
        int z=1;
        while(z!=(n/2)+1){
            z++;
            // cout<<temp->val<<"#";
            temp=temp->next;
            
        }
        
        return temp;
        
    }
};


// using fast and slow pointers

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
    ListNode* middleNode(ListNode* head) {
        
        if(head==NULL || head->next==NULL){
            return head;
        }
        
        ListNode*slow=head;
        ListNode*fast=head;
        
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        return slow;
        
    }
};