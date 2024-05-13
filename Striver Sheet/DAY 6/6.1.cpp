//  find intersection of two linked list

// brute force approach use two while loop 
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        while(headA!=NULL){
            ListNode*temp=headB;
            while(temp!=NULL){
                if(temp==headA){
                    return temp;
                }
                temp=temp->next;
            }
            headA=headA->next;
        }
        
        return NULL;
        
        
    }
};

//2 approach  use hashmap

// 3 approach  find lenth of both list then find the difference start longer list from difference steps ahead

// 4 aprroach instead of finding whenever one reaches null we sent it back to head of other ,so when they start again the will be 
// difference apart


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        if(headA==NULL || headB==NULL){
            return NULL;
        }
        
//         even if they dont meet ,they will reach NULL at same point and hence would be same i.e NULL
        
        ListNode*a= headA;
        ListNode*b=headB;
        
        while(a!=b){
            
            if(a==NULL){
                a=headB;
            }else{
                a=a->next;
            }
            
            if(b==NULL){
                b=headA;
            }else{
                b=b->next;
            }
            
        }
        
        return a;
        
        
    }
};
