#include<iostream>
#include<queue>
#include<vector>
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
// we have declare max level by refrence so it does not a make copy and change according to us
void printRightView(node*root,int level, int &maxlevel){
    if(root==NULL){
        return;
    }

    if(maxlevel < level){
        // means we have discover a new level
        cout<<root->data<<" ";
        maxlevel=level;
    }

    // right
    // left
    printRightView(root->right,level+1,maxlevel);
    printRightView(root->left,level+1,maxlevel);

}
 

int main(){

    node*root=buildTree();
    int a=-1;
    printRightView(root,0,a);
    bfs_print_levelwise2(root);
    cout<<endl;
    
    
    
}

// 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 14 13 -1 -1 -1 -1

// 8 10 1 -1 -1 -1 3 6 -1 -1 -1