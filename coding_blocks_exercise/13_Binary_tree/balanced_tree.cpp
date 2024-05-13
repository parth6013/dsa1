// BALANCED TREE ,if abs(left height-right_height)<=1


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
    if(root==NULL){
        return 0;
    }

    return( 1 +  max(height(root->left),height(root->right)));
}

int balanced_check(node*root){
    int f=0;
    if(root==NULL){
        return 0;
    }

    if(abs(height(root->left)-height(root->right))>1){
        cout<<"NO";
        return f=1;
        exit;

    }
    if(f==1){
        exit;
    }
    balanced_check(root->left);
    balanced_check(root->right);

    return 0;

}

class hb{
    public:
    int height;
    bool balance;
};

// video
hb check_balanced2(node*root){

    hb p;
    if(root==NULL){
        p.height=0;
        p.balance=true;

        return p;
    }
    hb left =check_balanced2(root->left);
    hb right =check_balanced2(root->right);

    p.height= max(left.height,right.height) +1;

    if(abs(left.height - right.height)<=1 && left.balance && right.balance){
        p.balance=true;
    }
    else{
        p.balance=false;
    }

    return p;



}


int main(){

    node*root=buildTree();
    
    bfs_print_levelwise2(root);

    // cout<<height(root);
    // int m=balanced_check(root);
    // if(m==0){
    //     cout<<"yes";
    // }

    hb x= check_balanced2(root);
    if(x.balance){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
}

// 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 14 13 -1 -1 -1 -1

// 8 10 1 -1 -1 -1 3 6 -1 -1 -1