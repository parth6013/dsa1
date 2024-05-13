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

void printKth_level(node*root,int k){

    if(root==NULL || k<0){
        return;
    }

    if(k==0){
        cout<<root->data<<" ";
        return;
    }

    printKth_level(root->left,k-1);
    printKth_level(root->right,k-1);
    return;

}

int printAtDistance(node*root,node*target,int k){

    // base case
    if(root==NULL){
        return -1;
    }

    // reach the target node
    if(root==target){
        printKth_level(target,k);
        return 0;
    }

    // next step -ancestor
    int DL = printAtDistance(root->left,target,k);

// if we havent found target it will be -1 and it will traverse otherwise we have found
    if(DL!=-1){
        // again 2 cases ancestor itself at k or we need to go right
        if(DL+1==k){
            cout<<root->data<<" ";
        }else{
             printKth_level(root->right,k-2-DL);
        }
        return 1+DL;
        // now it will go to ancestor of direct ancestor of target
    }

    // now if its in right
    int DR = printAtDistance(root->right,target,k);

    if(DR!=-1){
        if(DR+1==k){
            cout<<root->data<<" ";

        }
        else{
            printKth_level(root->left,k-2-DR);
        }
        return 1 + DR;
    }
    // node was ot present in left and right child
    return -1;
}

int main(){

    node*root=buildTree();
    node*target=root->left;
    bfs_print_levelwise2(root);
    printAtDistance(root,target,2);

    cout<<endl;

    
    
    
    
}

// 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 14 13 -1 -1 -1 -1

// 8 10 1 -1 -1 -1 3 6 -1 -1 -1