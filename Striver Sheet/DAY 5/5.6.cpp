// add two sum

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode*ans=new ListNode();
        ListNode*dum=ans;

        int carry=0;
        int sum=0;
        
        
        
        while(l1!=NULL || l2!=NULL || carry==1){
            // cout<<"uo";
            sum=0;
            if(l1!=NULL){
                sum=sum+l1->val;
                l1=l1->next;
            }
            if(l2!=NULL){
                sum=sum+l2->val;
                l2=l2->next;
            }
            // cout<<"oks";
            
            sum=sum+carry;
            ListNode*temp=new ListNode(sum%10);
            dum->next=temp;
            dum=dum->next;
            carry=sum/10;
            
            
            
            
        }
        return ans->next;
        
        
        
    }
};