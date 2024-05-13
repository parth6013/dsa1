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

// here s and e from in oreder array
node* createTreeFromTrav(int *in,int *pre,int s,int e){

    // static variable is variable is which is initialez once only 
    static int  i=0;

    // BASE CASE
    if(s>e){
        return NULL;
    }

    // Rec Case
    node *root= new node(pre[i]);

    int index=-1;

    for(int j=s;s<=e;j++){
        if(in[j]==pre[i]){
            index=j;
            break;
        }
    }

    i++;
    root->left = createTreeFromTrav(in,pre,s,index-1);
    root->right = createTreeFromTrav(in,pre,index+1,e);

    return root;
}


int main(){

    int a[]={1,2,3,4,5,6,7};

   int in[]={3,2,8,4,1,6,7,5};
   
   int pre[]={1,2,3,4,8,5,6,7};

   int n=sizeof(in)/sizeof(int);

   node*root=createTreeFromTrav(in,pre,0,n-1);


    bfs_print_levelwise2(root);


    return 0;
}
// 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 14 13 -1 -1 -1 -1

// 8 10 1 -1 -1 -1 3 6 -1 -1 -1

// Open page https://iplogger.org/shortener/ and paste any URL or link that you want to shorten.
// Click on "Shorten URL"
// In the field called "Your IPLogger link for collecting statistics" you will see your new short IPLogger link that will redirect on the URL that you entered earlier on step 1.
// Sel ect a domain name that will be used in your IPLogger link: iplogger.com, iplogger.org, 2no.co, yip.su, etc.
// Remember the link in the field called "Link for viewing statistics". This link will be required to access statistics with logs in future. You can add this link to your bookmarks by clicking "Bookmark" next to the link for viewing statistics or you can also copy paste this link to some file in notepad or any other app.
// Click on "Copy" next to your short IPLogger link (field called "Your IPLogger link for collecting statistics"). Your short IPLogger link is now in clipboard.
// Share the short IPLogger link via facebook, WhatsApp, Viber, Telegram, email or any other messenger or forum.
// Click on "Logged IP’s" tab or open the link for viewing statistics to see the detailed statistics of all clicks on your short IPLogger link and get information about all users that clicked on your short IPLogger link.