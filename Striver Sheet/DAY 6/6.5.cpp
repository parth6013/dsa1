// Finding the head of starting point of loop


//  brute force use hashmap

#include<bits/stdc++.h>
using namespace std;


//   Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        map<ListNode*,int> mpp;
        
        while(head!=NULL){
            if(mpp.find(head)!=mpp.end()){
                return head;
            }else{
                mpp[head]=1;
            }
            head=head->next;
        }
        
        return NULL;
        
        
    }
};


// slow pointer fast pointer where first meet then start entry pointer from start and where this meet with slow pointer

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        if(head==NULL || head->next==NULL){
            return NULL;
        }
        
        ListNode*slow=head;
        ListNode*fast=head;
        
        while(fast->next!=NULL && fast->next->next!=NULL){
       
            slow=slow->next;
            fast=fast->next->next;
                 if(slow==fast){
                break;
            }
        }
        
        // cout<<slow->val;
        
        ListNode*entry=head;
        if(slow!=NULL && fast->next!=NULL && fast->next->next!=NULL){
            while(slow!=entry){
                slow=slow->next;
                entry=entry->next;
            }
            return entry;
        }
        
        
        return NULL;
        
    }
};