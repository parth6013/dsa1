// Sort an array of 0's 1's & 2's

// https://leetcode.com/problems/sort-colors/


// Approach 1 we could sort them  O(nlogn)
// Approach 2 we could make a count sort(first count the number of 0,1,2) then push o(n) +o(n)

// Approach 3 DUTCH NATIONAL FLAG ALGORITHM

// In this we keep a pointer low at 0,mid at 0 ,high at n-1 ,
// our goal is all zero must come at left of low
// all 2 at right of high
// So we if mid=0 we swap with low and increase both
// if mid =1 we increase mid (no change)
// if mid =2 we swap with high and decraese high we dont do anything to mid cause after exchange it may took another swap
// so we want mid to stay there


#include<iostream>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    void sortColors(vector<int>& nums) 
    {
        int tmp = 0, low = 0, mid = 0, high = nums.size() - 1;
    
        while(mid <= high)
        {
            if(nums[mid] == 0)
            {
             swap(nums[low],nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid] == 1)
            {
                mid++;
            }
            else if(nums[mid] == 2)
            {
                swap(nums[mid],nums[high]);
                high--;
            }
                        
                    for(int j=0;j<nums.size();j++){
            cout<<nums[j]<<" ";
        }
            cout<<"##"<<endl;
        }
    }
};