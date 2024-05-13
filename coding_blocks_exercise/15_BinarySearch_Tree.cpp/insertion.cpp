#include<iostream>
#include<queue>
using namespace std;

class node{
    public:
    int data;
    node*left;
    node*right;

    node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }


};

node* insertInBst(node*root,int data){
    // base case
    if(root==NULL){
        return new node(data);
    }
    // Rec case - insert in subtree and update
    if(data<=root->data){
        root->left= insertInBst(root->left,data);
    }else{
        root->right= insertInBst(root->right,data);
    }
    return root;
}

node* build(){
    // read a list of numbers till -1 and also these numbers will be inserted into bst
    int d;
    cin>>d;

    node*root=NULL;

    while(d!=-1){
        root=insertInBst(root,d);
        cin>>d;
    }
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

bool search(node*root,int d){
    if(root==NULL){
        cout<<"NO";
        return false;
    }
    if(root->data==d){
        cout<<"yes";
        return true;
    }

    if(d>root->data){
        search(root->right,d);

    }else{
        search(root->left,d);
    }
}

int main(){

    node*root=build();
    bfs_print_levelwise2(root);
    search(root,9);



    
}