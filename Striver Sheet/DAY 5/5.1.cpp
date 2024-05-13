//  reverse linked list

#include<bits/stdc++.h>
using namespace std;


//   Definition for singly-linked l
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  
  };
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        if(head==NULL || head->next==NULL){
            return head;
        }
        
        ListNode*pres=head;
        ListNode*succ=head;
        ListNode*pre=NULL;
        
        while(succ->next!=NULL){
            succ=pres->next;
            pres->next=pre;
            pre=pres;
            pres=succ;
        }
        pres->next=pre;
        
        return pres;
        
        
    }
};