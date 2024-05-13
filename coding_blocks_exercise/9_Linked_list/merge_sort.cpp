#include<iostream>
using namespace std;
// tail -> next = *tail.next
class node{
public:
    int data;
    node*next;

    node(int d){
        data = d;
        next = NULL;
    }

};

// passing a pointer by refrence
void insertAtHead(node*&head,int d){

if(head==NULL){
    node*n = new node(d);
    head=n;
    // we use return so it exits the function
    return;
}

node*n= new node(d);
n -> next = head;
head=n;

}
// here we pass by value ,in passing by value a copy is passed so no actual change
// is made in orignal and we can print it twice in passing by refrence orignal copy is change
void print(node*head){

    while(head!=NULL){
        cout<<head ->data<<"#"<<endl;
        head=head->next;
    }

}

void insertAtTail(node*&head,int data){

if(head==NULL){
    head = new node(data);
    return;
}
node*tail =head;
while(tail->next!=NULL){
    tail=tail->next;
}

tail->next= new node(data);
return;


}

int length(node*head){
    int cnt=0;
    while(head!=NULL){
        cnt++;
        head=head->next;
    }

    return cnt;
}

void insertInMiddle(node*&head,int data,int p){

    

    if( p==0 || head==NULL){
        insertAtHead(head,data);
    }

    else if(p>length(head)){
        insertAtTail(head,data);
    }
    else{
        
        node*temp=head;
        int jump=1;
        while(jump<=p-1){
            temp=temp ->next;
            jump++;

        }
        node*n = new node(data);
        n->next = temp -> next;
        temp->next = n;

    }



}
//  
node* take_input(){

    int d;
    cin>>d;

    node*head=NULL;

    while(d!=-1){
        insertAtHead(head,d);
        cin>>d;
    }

    return head;

}
// we could have done by using two while loop first to find length and another to find l/2
node* midpoint(node*head){

if(head==NULL || head->next==NULL){
    return head;
}

node*slow=head;
node*fast=head->next;

while(fast!=NULL && fast->next!=NULL){
slow=slow->next;
fast=fast->next->next;
}
return slow;
}



node*join(node*a,node*b){
    if(a==NULL){
        return b;
    }
    if(b==NULL){
        return a;
    }
    node*c;

    if(a->data<=b->data){
        c=a;
        c->next=join(a->next,b);
    }
    else{
        c=b;
        c->next=join(a,b->next);
    }
    return c;
}

node*merge_sort(node*head){

if(head==NULL || head->next==NULL){
    return head;
}

node*l=midpoint(head);
node*a=head;
node*b=l->next;
l->next=NULL;
// recursive part
a=merge_sort(a);
b=merge_sort(b);

// join broken parts

node*c=join(a,b);

return c;



}







int main(){


node*m=take_input();
node*m2=merge_sort(m);
print(m2);



}