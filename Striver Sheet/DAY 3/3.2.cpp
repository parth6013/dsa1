// to calculate pow(x,n)

// use brute force

// use logn method using bitwise operator

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    double myPow(double x, int n) {
        
        if(n==0){
            return 1;
        }
        
       double ans=1;
        
        if(n>0){
            
            while(n>0){
                
                int a1=n&1;
                
                if(a1==1){
                    ans=ans*x;
                    x=x*x;
                    
                    
                }else{
                    x=x*x;
                }
                
                n=n>>1;
                
                
            }
            
        }
        
        if(n<0){
            
            n=abs(n);
            
                        while(n>0){
                
                int a1=n&1;
                
                if(a1==1){
                    ans=ans*x;
                    x=x*x;
                    
                    
                }else{
                    x=x*x;
                }
                
                n=n>>1;
                
                
            }
            
            ans=1/ans;
        }
        
        return ans;
        
        
    }
};
