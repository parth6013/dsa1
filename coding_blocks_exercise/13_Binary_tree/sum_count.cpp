#include<iostream>
#include<queue>
using namespace std;

class node{

public:
    // intialization
    int data;
    node*left;
    node*right;
    // constructor
    node(int d){
        data= d;
        left=NULL;
        right=NULL;


    }


};

node*buildTree(){

    int d;
    cin>>d;

    if(d==-1){
        return NULL;
    }

    node*root=new node(d);

    root->left=buildTree();
    root->right=buildTree();

    return root;

}

void bfs_print_levelwise(node*root){

    queue<node*> q1;

if(root!=NULL){
    q1.push(root);
}
else{
    cout<<"NOT VALID"<<endl;
}

    while(!q1.empty()){

        node*a=q1.front();
        cout<<a->data;
        if(a->left!=NULL){
            q1.push(a->left);
        }
        if(a->right!=NULL){
            q1.push(a->right);
        }

        cout<<endl;
        q1.pop();
    }



}

void bfs_print_levelwise2(node*root){

    queue<node*> q1;

if(root!=NULL){
    q1.push(root);
}
else{
    cout<<"NOT VALID"<<endl;
}
    q1.push(NULL);
    
    while(!q1.empty()){

        node*a=q1.front();
        if(a==NULL){
            cout<<endl;
            q1.pop();

            if(!q1.empty()){
                q1.push(NULL);
            }
        }
        else{

        cout<<a->data<<" ";
        if(a->left!=NULL){
            q1.push(a->left);
        }
        if(a->right!=NULL){
            q1.push(a->right);
        }

        
        q1.pop();
        }
    }



}


int count(node*root){
    
    int ans=0;

    if(root==NULL){
        return 0;
    }

    return 1 + count(root->left) + count(root->right);

}

int sum(node*root){
    
    int ans=0;

    if(root==NULL){
        
        return 0;
    }

    ans= ans + root->data;

    sum(root->left);
    sum(root->right);

    
     return ans + sum(root->left)+ sum(root->right);

}

int main(){

    node*root=buildTree();
    // bfs_print_levelwise(root);
    bfs_print_levelwise2(root);
    cout<<count(root)<<"x"<<endl;
    cout<<sum(root)<<"@";

}