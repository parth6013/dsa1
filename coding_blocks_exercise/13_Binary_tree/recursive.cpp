#include<iostream>
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

void print_pre(node*root){

    if(root==NULL){
        return ;
    }

    cout<<root->data<<endl;

    print_pre(root->left);
    print_pre(root->right);

}

void print_in(node*root){

    if(root==NULL){
        return;
    }


    print_in(root->left);
    cout<<root->data<<endl;
    print_in(root->right);

}
void print_post(node*root){
    if(root==NULL){
        return;
    }

    print_post(root->left);
    print_post(root->right);
    cout<<root->data<<" ";


}



int maxDepth(node* node)
{
    if (node == NULL)
        return 0;
    else
    {
        /* compute the depth of each subtree */
        int lDepth = maxDepth(node->left);
        int rDepth = maxDepth(node->right);
     
        /* use the larger one */
        if (lDepth > rDepth)
            return(lDepth + 1);
        else return(rDepth + 1);
    }
}


void printKth_level(node*root,int k){

    if(root==NULL){
        return;
    }

    if(k==1){
        cout<<root->data<<" ";
        return;
    }

    printKth_level(root->left,k-1);
    printKth_level(root->right,k-1);
    return;

}


void print_allLevels(node*root){

    int h=maxDepth(root);

    for(int i=1;i<=h;i++){
        printKth_level(root,i);
        cout<<endl;
    }

}

int main(){

node*root=buildTree();
print_pre(root);
cout<<"xxx"<<endl;
print_in(root);
cout<<"xxx"<<endl;
print_post(root);
cout<<"xxx"<<endl;
// int h=maxDepth(root);
// cout<<h;

// printKth_level(root,3);
print_allLevels(root);

}

// 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 14 13 -1 -1 -1 -1