// Flattening of Linked List

// https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1

// { Driver Code Starts

// brute using extra vector then sort it 
#include <bits/stdc++.h>

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

using namespace std;

Node *flatten(Node *root)
{
   vector<int> nums;
   
   
   while(root){
      Node* temp=root;
       while(temp){
           nums.push_back(temp->data);
           temp=temp->bottom;
       }
       root=root->next;
   }
   
   sort(nums.begin(),nums.end());
   
   int n=nums.size();
   Node*head=new Node(nums[0]);
   Node*temp=head;
   int i=1;
   while(n-1>0){
       temp->bottom=new Node(nums[i]);
       temp=temp->bottom;
       i++;
       n--;
   }
   
   return head;
   
   
   
   
   
}

// second using merge sort taking two at a time

