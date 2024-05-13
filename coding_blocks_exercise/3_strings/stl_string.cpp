#include<iostream>
#include<string>
using namespace std;

int main(){

string s0;
string s1("hello");

string s2="hello world";

string s3(s2);
string s4=s3;

char a[]={'a','v','f','\0'};

string s5(a);

cout<<s0<<endl;
cout<<s1<<endl;
cout<<s3<<endl;
cout<<s4<<endl;
cout<<s5<<endl;



}