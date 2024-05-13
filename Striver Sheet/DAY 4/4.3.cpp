// longest consecutive subsequence

// brute force
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        if(nums.size()==0){
            return 0;
        }
        
        int ans=0;
        int cnt=1;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        
        
        for(int i=0;i<n-1;i++){
            if(nums[i+1]==nums[i]+1){
                // cout<<"a";
                cnt++;
            }else if(nums[i+1]==nums[i]){
                // cout<<"b";
                cnt=cnt;
            }
            
            else{
                // cout<<"c";
                ans=max(ans,cnt);
                cnt=1;
            }
            
            
        }
        
        ans=max(ans,cnt);
        
        return ans;
        
        
        
    }
};


// by using hash map  ,fist we will push all the elemets in map
// then we will pick the lowest element available in series and start counting from there
// O(n)+O(n)+O(n)


class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> num_set;
        int max_count = 0, count = 0;

        for (auto n : nums) {
            num_set.insert(n);
        }

        // if no smaller element than this is in set
        for (auto n : num_set) {
            if (!num_set.count(n - 1)) {
                count = 0;
                while (num_set.count(n)) {
                    count++;
                    n = n + 1;
                }
                max_count = max(count, max_count);
            }
        }
        return max_count;
    }
};