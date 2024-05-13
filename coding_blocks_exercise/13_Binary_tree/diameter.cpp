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

int height(node*root){
    int h=0;
    if(root==NULL){
        return 0;
    }else{
        h=h+1;
    }

    return h + max(height(root->left),height(root->right));

}

int diameter(node*root){

    int r1= height(root->left) + height(root->right);
    int r2= height(root->left->left)+height(root->left->right);
    int r3= height(root->right->left)+ height(root->right->right);

    int a= max(r1,r2);
    int b= max(a,r3);

    return b;

}

int main(){

    node*root=buildTree();
    
    bfs_print_levelwise2(root);
    cout<<height(root)<<"x";
    cout<<diameter(root)<<"@";
}