#include<iostream>
#include<list>
using namespace std;

int main(){

list<int> l1= {1,2,3,4,5};

list<string> l2 {"apple","pineapple","mango","guava"};

// sort
l2.sort();



for(auto s : l2){
    cout<<s<<"-->";
}

cout<<endl;
// reverse
l2.reverse();
for(auto s : l2){
    cout<<s<<"-->";
}

l2.push_back("strawberry");
l2.push_front("litchi");


cout<<endl;
for(auto s : l2){
    cout<<s<<"-->";
}

l2.pop_front();
l2.pop_back();
// removes all occurence of mango
l2.remove("mango");

auto it = l2.begin();
// 1st index
it++;
// removes 1 index
l2.erase(it);

auto it2=l2.begin();
l2.insert(it2,"bhai");


cout<<endl;
for(auto s : l2){
    cout<<s<<"-->";
}

}