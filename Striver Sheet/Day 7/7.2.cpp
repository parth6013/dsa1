// 3 sum 

// brute approach use 3 loops  and a set
// first form a hash table then using two loop check for third element in hashmap
// remove first two elements from hash while searching for third then add again ,add sorted elements in set
// insertion in set is log(n)


// most optimum one loop and two pointer in sorted array and manipulation for non repeating

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    for (unsigned int i=0; i<nums.size(); i++) {
        if ((i>0) && (nums[i]==nums[i-1]))
            continue;
        int l = i+1, r = nums.size()-1;
        while (l<r) {
            int s = nums[i]+nums[l]+nums[r];
            if (s>0) r--;
            else if (s<0) l++;
            else {
                res.push_back(vector<int> {nums[i], nums[l], nums[r]});
                while (nums[l]==nums[l+1]) l++;
                while (nums[r]==nums[r-1]) r--;
                l++; r--;
            }
        }
    }
    return res;
}
};