#include<bits/stdc++.h>
using namespace std;

// merging two sorted array without extra space



// intution let it be array of size m+n ,we will swap with gap=gap/2 ceil
// implementaion og gap method


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        double m1 = m;
        double n1 =n;
        
        double gap = ceil((n+m)/2);
        
        while(gap>1){
            cout<<gap<<endl;
            int i=0;
            while(i+gap<=m+n-1){
                if(i<=m-1 && i+gap>m-1 && nums1[i]>nums2[i+gap-m]){
                    
                        swap(nums1[i],nums2[i+gap-m]);
                    }
                     if (i<=m-1 && i+gap<=m-1 && nums1[i]>nums1[i+gap]){
                        swap(nums1[i],nums1[i+gap]);
                    }
                    if(i>m-1 && gap+i>m-1 && nums2[i-m]>nums2[gap+i-m]){
                        swap(nums2[i-m],nums2[gap+i-m]);
                    }
                    
                    for(int k=0;k<m;k++){
                        
                        cout<<nums1[k]<<" ";
                    }
                    cout<<endl;
                                    
                    for(int k=0;k<n;k++){
                        
                        cout<<nums2[k]<<" ";
                    }
                    cout<<"##"<<endl;
                
                    i++;
                    
                
                }
            
              gap=ceil(gap/2);
            
                
            }
        gap=1;
        int i=0;
         while(i+gap<=m+n-1){
                if(i<=m-1 && i+gap>m-1 && nums1[i]>nums2[i+gap-m]){
                    
                        swap(nums1[i],nums2[i+gap-m]);
                    }
                     if (i<=m-1 && i+gap<=m-1 && nums1[i]>nums1[i+gap]){
                        swap(nums1[i],nums1[i+gap]);
                    }
                    if(i>m-1 && gap+i>m-1 && nums2[i-m]>nums2[gap+i-m]){
                        swap(nums2[i-m],nums2[gap+i-m]);
                    }
                    
                    for(int k=0;k<m;k++){
                        
                        cout<<nums1[k]<<" ";
                    }
                    cout<<endl;
                                    
                    for(int k=0;k<n;k++){
                        
                        cout<<nums2[k]<<" ";
                    }
                    cout<<"##"<<endl;
                
                    i++;
                    
                
                }
            for(int l=0;l<n;l++){
                nums1[m+l]=nums2[l];
            }
            
        }
        
    
};