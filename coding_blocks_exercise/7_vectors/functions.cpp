#include<iostream>
#include<vector>
using namespace std;

int main(){

vector<int> d{1,2,3,10,14};

d.push_back(16);

// removes last element
d.pop_back();

// inset value  at 3 index
d.insert(d.begin() + 3,100);
// add 2 100 at 3 index
d.insert(d.begin() + 3,2,100);

// erase at 3 position
d.erase(d.begin()+3);

// erase 2 elements starting from 3 index
d.erase(d.begin() +3,d.begin()+5);

// size

cout<<d.size()<<endl;

// remove all
d.clear();

// empty
if(d.empty()){
    cout<<d.size()<<endl;
}

d.push_back(10);
d.push_back(20);

cout<<d.back()<<" "<<d.front();



for(int x:d){
    cout<<x<<",";
}
// To avoid doubling we will use reserve function

vector<int> v;
int n =5;
v.reserve(1000);

for(int i=0;i<n;i++){
    int no;
    cin>>no;

    v.push_back(no);
    cout<<"Changing capacity"<<v.capacity()<<endl;

}



}