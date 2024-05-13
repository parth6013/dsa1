// C++ program to reverse a stack
// by using an extra stack
#include <bits/stdc++.h>
using namespace std;

// Function to transfer elements of
// the stack s1 to the stack s2
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        

        
        for(int i=0;i<s.length();i++){
            if((stk.size()==0) & (s[i]=='}'|| s[i]==']'|| s[i]==')') ){
                cout<<"1";
                return false;
            }
            else if (stk.size()==0){
                stk.push(s[i]);
            }
            else{
                if(s[i]=='}' & stk.top()=='{'){
                    stk.pop();
                }
                else if(s[i]==')' & stk.top()=='('){
                    stk.pop();
                }
                else if(s[i]==']' & stk.top()=='['){
                    stk.pop();
                } 
                else{
                    stk.push(s[i]);
                }
            }
        }
        
        if(stk.size()!=0){
            cout<<'2';
            return false;
        }
        // while(stk.size()!=0){
        //     cout<<stk.top()<<endl;;
        //     stk.pop();
        // }
            
    return true;
    }
};
