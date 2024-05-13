// Valid Anagram

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        
        vector<int> arr(26,0);
        vector<int> arr2(26,0);

        

        
        for(int i=0;i<s.size();i++){
            
            arr[s[i]-'a']++;
            
           
            
        }
                
        for(int i=0;i<t.size();i++){
            
            arr2[t[i]-'a']++;
            
           
            
        }
        
        
        
        for(int i=0;i<arr.size();i++){
            if(arr[i]!=arr2[i]){
                return false;
            }
            
        }
        
        
        return true;
        
                

 
        
    }
};