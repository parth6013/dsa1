#include<iostream>
#include<vector>
using namespace std;

int main(){
// ways you can create and initialize a vector
vector<int> a;
vector<int> b(5,10); // five int with value 10

vector<int> c(b.begin(),b.end());

vector<int> d{1,2,3,10,14}; 

// ways to iterate

for(int i=0; i<c.size();i++){
    cout<<c[i]<<",";
}
cout<<endl;


for(auto it = b.begin();it !=b.end();it++){
    cout<<(*it)<<",";
} 
cout<<endl;
// for each loop
for(int x:d){
    cout<<x<<",";
}
cout<<endl;
// to take input from user

vector<int> v;
int n;
cin>>n;
for(int i=0;i<n;i++){
    int no;
    cin>>no;
    // add element to the last
    v.push_back(no);
}
 
for(int x:v){
    cout<<x<<",";
}

return 0;
}