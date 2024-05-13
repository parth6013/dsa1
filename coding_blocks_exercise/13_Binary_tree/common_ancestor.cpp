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
// assuming both a and b are present
node*lca(node*root,int a,int b){
    if(root==NULL){
        return NULL;
    }

    // base case or when we have find
    if(root->data==a || root->data==b){
        return root;
    }
    node*leftans=lca(root->left,a,b);
    node*rightans=lca(root->right,a,b);

// matlab dono jagah se answer a gya jis point pe wapas reach kiya return that
    if(leftans!=NULL and rightans!=NULL){
        return root;
    }
// if one is null and one is not so if we find left first then is the ancestor root only
if(leftans !=NULL){
    return leftans;
}
// otherwise right root
return rightans;


}




int main(){

    node*root=buildTree();
    
    bfs_print_levelwise2(root);

    node*main=lca(root,1,10);

    cout<<main->data<<"#";
    


    cout<<endl;

    
    
    
    
}

// 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 14 13 -1 -1 -1 -1

// 8 10 1 -1 -1 -1 3 6 -1 -1 -1