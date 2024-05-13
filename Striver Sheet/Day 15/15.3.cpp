#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        
        map<char,int> mpp;
        
        mpp.insert({'I',1});
        mpp.insert({'V',5});
        mpp.insert({'X',10});
        mpp.insert({'L',50});
        mpp.insert({'C',100});
        mpp.insert({'D',500});
        mpp.insert({'M',1000});
        
        // for(auto x:mpp){
        //     cout<<x.first<<x.second<<endl;
        // }
        
        int ans=0;
 
        
        int n=s.size();
        
        for(int i=0;i<n;i++){
            if(i!=n-1 && s[i]=='I' &&s[i+1]=='V' ){
                ans+=4;
                i++;
            }
                        else if(i!=n-1 && s[i]=='I' &&s[i+1]=='X' ){
                ans+=9;
                i++;
            }
                       else if(i!=n-1 && s[i]=='X' &&s[i+1]=='L' ){
                ans+=40;
                            i++;
            }
                        else if(i!=n-1 && s[i]=='X' &&s[i+1]=='C' ){
                ans+=90;
                             i++;
            }
                        else if(i!=n-1 && s[i]=='C' &&s[i+1]=='D' ){
                ans+=400;
                             i++;
            }
                        else if(i!=n-1 && s[i]=='C' &&s[i+1]=='M' ){
                ans+=900;
                             i++;
            }else{
                            auto a=mpp.find(s[i]);
                            // cout<<s[i]<<a->second<<endl;
                            
                            ans+=a->second;
                        }
        }
        
        
        return ans;
        
        
    }
};