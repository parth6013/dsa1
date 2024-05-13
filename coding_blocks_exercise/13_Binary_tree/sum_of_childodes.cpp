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

int sum1(node*root){

    int sum ;

    if(root==NULL){
        return 0;
    }

    sum =  root->data;

    return sum + sum1(root->left) + sum1(root->right);

}

int sum_of_child(node*root){
    int t_sum = sum1(root);
    return t_sum-root->data;


}

// pre order traversal mine

void new3(node*root){
    
    if(root==NULL){
        return;
    }
    
    else{
        if(root->left!=NULL || root->right!=NULL){
        int x = sum_of_child(root);
        root->data=x;
        }


         new3(root->left);
         new3(root->right);
    }


}
// post order traversal in video
int replaceSum(node*root){
    if(root==NULL){
        return 0;
    }
    if(root->left==NULL && root->right==NULL){
        return root->data;
    }

    int leftsum=replaceSum(root->left);
    int rightSum=replaceSum(root->right);

    int temp=root->data;
    root->data=leftsum +rightSum;
    return temp + root->data;

}


int main(){

    node*root=buildTree();
    
    bfs_print_levelwise2(root);
    // cout<<endl;

    // cout<<sum_of_child(root)<<"#";

    // new3(root);
    // cout<<endl;
    replaceSum(root);
    bfs_print_levelwise2(root);

}

// 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 14 13 -1 -1 -1 -1