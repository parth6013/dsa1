// longest non repeating  substring


// using vetcor array of 256 char

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        vector<int> mpp(256,-1);
        int n=s.size();
        int len=0;
        int left=0;
        int right=0;
        
        while(right<n){
            
            if(mpp[s[right]]!=-1){
// where we have last seen that index +1 ,but if lies in left of wherever left is right now we dont care
                left=max(mpp[s[right]]+1,left);
            }
            
            mpp[s[right]]=right;
            len=max(len,right-left+1);
            right++;
            
        }
        
        return len;
        
    }
};

// using hashmap
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
         unordered_map<char,int> mpp;
        int n=s.size();
        int len=0;
        int left=0;
        int right=0;
        
        while(right<n){
            
            if(mpp.find(s[right])!=mpp.end()){
// where we have last seen that index +1 ,but if lies in left of wherever left is right now we dont care
                left=max(mpp[s[right]]+1,left);
            }
            
            mpp[s[right]]=right;
            len=max(len,right-left+1);
            right++;
            
        }
        
        return len;
        
    }
};





