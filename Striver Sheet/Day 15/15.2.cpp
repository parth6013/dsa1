// longest palindrome in string 

#include<bits/stdc++.h>
using namespace std;

// pure brute force but gives tle
class Solution {
public:
    
    bool check_palin(string x){
        int n=x.size();
        int i=0;int j=n-1;
        while(i<j){
            if(x[i]!=x[j]){
                return false;
            }
            i++;
            j--;
        }
        
        return true;
        
    }
    
    string longestPalindrome(string s) {
        

        
        string ans;
        int s_size=0;
        
        int n=s.size();

        
        for(int i=0;i<n;i++){
            for(int j=1;j<=n-i;j++){
                string x=s.substr(i,j);
            // cout<<x<<endl;
                if(check_palin(x)){
                    if(x.size()>s_size){
                        ans=x;
                        s_size=x.size();
                    }
                }
            }
        }
        

        
        return ans;
        
        
    }
};